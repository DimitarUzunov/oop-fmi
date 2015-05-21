#include <cstring> // strlen
#include "cfg.h"

bool CFG::isEps(const char* str) const {
	return str[0] == '\0';
}

bool CFG::isTerminal(char c) const {
	return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool CFG::containsTerm(const char* str) const {
	while (*str) {
		if ((*str >= 'a' && *str <= 'z') ||
				(*str >= '0' && *str <= '9')) return true;
		str++;
	}
	return false;
}

bool CFG::productionExists(char left, const char* right) const {
	for (int i = 0, count = productions.getSize(); i < count; i++) {
		if (Production(left, right) == productions[i]) return true;
	}
	return false;
}

void CFG::addTerminal(char terminal) {
	terminals.pushBack(terminal);
	if (terminal >= '0' && terminal <= '9') isUsedTerm[terminal - '0'] = true;
	else isUsedTerm[terminal - 'a' + 10] = true;
}

void CFG::createProduction(const Production& production) {
	productions.pushBack(production);
}

char CFG::getNewNonterm() const {
	for (int i = 0; i < NONTERMS; i++) {
		if (!isUsedNonterm[i]) return i + 'A';
	}
	return '\0';
}

void CFG::addNonterminal(char nonterminal) {
	nonterminals.pushBack(nonterminal);
	isUsedNonterm[nonterminal - 'A'] = true;
}

// remove productions with right side length > 2
void CFG::removeLongProductions() {
	int prodCount = productions.getSize();
	for (int i = 0; i < prodCount; i++) {
		// initialize iterators
		const char* right = productions[i].getRight();
		int rightLen = strlen(right);
		char currentLeft = productions[i].getLeft();
		char currentRight = right[0];

		// make a chain of productions with right side length = 2
		while (rightLen > 2) {
			// add new nonterminal
			char newNonterm = getNewNonterm();
			addNonterminal(newNonterm);

			// add new production
			char newRight[3] = { '\0' };
			newRight[0] = currentRight;
			newRight[1] = newNonterm;
			addProduction(currentLeft, newRight);

			// change iterators
			currentLeft = newNonterm;
			currentRight = *(++right);
			rightLen--;

			// special case -- add the last production and delete long production
			if (rightLen == 2) {
				newRight[0] = currentRight;
				newRight[1] = *(++right);
				addProduction(currentLeft, newRight);

				// remove long production
				removeProduction(i);
				prodCount--;
				i--; // don't miss the production after the removed one
			}
		}
	}
}

int CFG::nontermCountInProd(char nonterm, const Production& prod) const {
	int count = 0;
	const char* right = prod.getRight();
	while (*right) {
		if (*right == nonterm) count++;
		right++;
	}
	return count;
}

/* there are three cases for X-->eps:
	1) Y-->XX (count = 2) (add Y-->X)
	2) Y-->Xalpha (count = 1, add Y-->alpha)
	3) Y-->alphaX (count = 1, add Y-->alpha),
	where alpha is terminal or nonterminal,
	because epsilon removal is done after removing long productions
*/
void CFG::createProdCombinations(const Production& prod,
																char nonterm, int count) {
	const char* right = prod.getRight();

	char newRight[2] = { '\0' };
	if (right[0] != nonterm) newRight[0] = right[0];
	else newRight[0] = right[1];
	addProduction(prod.getLeft(), newRight);
}

void CFG::removeEpsProductions() {
	int prodCount = productions.getSize();
	for (int i = 0; i < prodCount; i++) {
		if (productions[i].getLeft() == start ||
				strlen(productions[i].getRight()) != 0) continue;

		// epsilon production found
		char epsProdLeft = productions[i].getLeft();

		// remove epsilon production
		removeProduction(i);
		prodCount--;
		i--; // don't miss the production after the removed one

		// iterate over all productions and generate combinations
		int newProdCount = productions.getSize();
		for (int j = 0; j < newProdCount; j++) {
			// no need to add new productions for right side length < 2
			if (strlen(productions[j].getRight()) < 2) continue;

			// get number of occurrences of epsilon nonterminal in current production
			int count = nontermCountInProd(epsProdLeft, productions[j]);

			// add new productions if nonterminal occurs in current production
			if (count) createProdCombinations(productions[j], epsProdLeft, count);
		}
	}
}

// remove productions with right side length = 2 and containing terminals
void CFG::removeTerminals() {
	int prodCount = productions.getSize();
	for (int i = 0; i < prodCount; i++) {
		const char* right = productions[i].getRight();
		int rightLen = strlen(right);
		if (rightLen != 2 || !containsTerm(right)) continue;

		// initialize main production
		char newProdLeft = productions[i].getLeft();
		char newProdRight[3] = { '\0' };

		for (int i = 0; i < rightLen; i++) {
			if (isTerminal(right[i])) {
				// add new nonterminal
				char newNonterm = getNewNonterm();
				addNonterminal(newNonterm);

				// add new production
				char term[2] = { '\0' };
				term[0] = right[i];
				addProduction(newNonterm, term);

				// construct main production
				newProdRight[i] = newNonterm;
			} else {
				// construct main production
				newProdRight[i] = right[i];
			}
		}

		// add main production
		addProduction(newProdLeft, newProdRight);

		// remove production
		removeProduction(i);
		prodCount--;
		i--; // don't miss the production after the removed one
	}
}

CFG::CFG(const char* nonterminals, const char* terminals, char start)
				: start(start) {
	for (int i = 0; i < NONTERMS; i++) isUsedNonterm[i] = false;
	for (int i = 0; i < TERMS; i++) isUsedTerm[i] = false;
	for (int i = 0, len = strlen(nonterminals); i < len; i++) {
		addNonterminal(nonterminals[i]);
	}
	for (int i = 0, len = strlen(terminals); i < len; i++) {
		addTerminal(terminals[i]);
	}
}

// check if the grammar is in Chomsky normal form
bool CFG::isInCNF() const {
	int prodCount = productions.getSize();
	for (int i = 0; i < prodCount; i++) {
		char left = productions[i].getLeft();
		const char* right = productions[i].getRight();
		int rightLen = strlen(right);
		if (rightLen == 0 ||
				rightLen > 2 ||
				(rightLen == 2 &&
					(containsTerm(right) || right[0] == start || right[1] == start)) ||
				(rightLen == 1 &&
					((left != start && !containsTerm(right)) ||
					(left == start && !containsTerm(right) && !isEps(right))))) {
			return false;
		}
	}
	return true;
}

// check if str is in the language of the grammar
bool CFG::contains(const char* str) {
	if (isEps(str)) return productionExists(start, "");

	int len = strlen(str);
	int nontermsCount = nonterminals.getSize();
	int prodCount = productions.getSize();

	// allocate memory
	bool*** isDerived = new bool**[len];
	for (int i = 0; i < len; i++) {
		isDerived[i] = new bool*[len];
		for (int j = 0; j < len; j++) {
			isDerived[i][j] = new bool[nontermsCount]();
		}
	}

	// CYK algorithm
	// base case -- all unit productions X-->str[i] in productions array
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < prodCount; j++) {
			char left = productions[j].getLeft();
			const char* right = productions[j].getRight();
			if (strlen(right) == 1 && right[0] == str[i]) {
				isDerived[0][i][left - 'A'] = true;
			}
		}
	}
	// induction -- all productions of type X-->YZ in productions array
	for (int i = 1; i < len; i++) { // i -- length of span in str
		for (int j = 0; j < len - i; j++) { // j -- start position of span
			for (int k = 0; k < i; k++) { // k -- partition of span
				for (int l = 0; l < prodCount; l++) {
					char left = productions[l].getLeft();
					const char* right = productions[l].getRight();
					if (strlen(right) == 2 &&
							isDerived[k][j][right[0] - 'A'] &&
							isDerived[i - k - 1][j + k + 1][right[1] - 'A']) {
						isDerived[i][j][left - 'A'] = true;
					}
				}
			}
		}
	}
	// check if str is derived from the start symbol
	bool result = isDerived[len - 1][0][start - 'A'];

	// free memory
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			delete[] isDerived[i][j];
		}
		delete[] isDerived[i];
	}
	delete[] isDerived;

	return result;
}

void CFG::addProduction(char left, const char* right) {
	productions.pushBack(Production(left, right));
}

void CFG::removeProduction(int index) {
	productions.removeAt(index);
}

std::ostream& operator<<(std::ostream& os, const CFG& cfg) {
	os << "Nonterminals: " << cfg.nonterminals << '\n'
		<< "Terminals: " << cfg.terminals << '\n'
		<< "Start: " << cfg.start << '\n';

	int prodCount = cfg.productions.getSize();
	if (prodCount) {
		os << "Productions:\n";
		for (int i = 0; i < prodCount - 1; i++) {
			os << cfg.productions[i] << '\n';
		}
		return os << cfg.productions[prodCount - 1];
	} else {
		return os << "There are no productions.";
	}
}

CFG unite(const CFG& grammar1, const CFG& grammar2) {
	// copy grammar1
	CFG newGrammar = grammar1;

	// unite nonterminals
	for (int i = 0, len = grammar2.nonterminals.getSize(); i < len; i++) {
		// TODO: check for name collisions
		newGrammar.addNonterminal(grammar2.nonterminals[i]);
	}

	// unite terminals
	for (int i = 0, len = grammar2.terminals.getSize(); i < len; i++) {
		char term = grammar2.terminals[i];
		if (term >= '0' && term <= '9' && !newGrammar.isUsedTerm[term - '0']) {
			newGrammar.addTerminal(term);
		} else if (!newGrammar.isUsedTerm[term - 'a' + 10]) {
			newGrammar.addTerminal(term);
		}
	}

	// unite productions
	for (int i = 0, len = grammar2.productions.getSize(); i < len; i++) {
		newGrammar.createProduction(grammar2.productions[i]);
	}

	// add new nonterminal
	char newStart = newGrammar.getNewNonterm();
	newGrammar.addNonterminal(newStart);

	// change start
	newGrammar.start = newStart;

	// add new productions
	char newProdRight[2] = { '\0' };
	newProdRight[0] = grammar1.start;
	newGrammar.addProduction(newStart, newProdRight); // S-->S1
	newProdRight[0] = grammar2.start;
	newGrammar.addProduction(newStart, newProdRight); // S-->S2

	return newGrammar;
}

CFG concatenate(const CFG& grammar1, const CFG& grammar2) {
	// copy grammar1
	CFG newGrammar = grammar1;

	// unite nonterminals
	for (int i = 0, len = grammar2.nonterminals.getSize(); i < len; i++) {
		// TODO: check for name collisions
		newGrammar.addNonterminal(grammar2.nonterminals[i]);
	}

	// unite terminals
	for (int i = 0, len = grammar2.terminals.getSize(); i < len; i++) {
		char term = grammar2.terminals[i];
		if (term >= '0' && term <= '9' && !newGrammar.isUsedTerm[term - '0']) {
			newGrammar.addTerminal(term);
		} else if (!newGrammar.isUsedTerm[term - 'a' + 10]) {
			newGrammar.addTerminal(term);
		}
	}

	// unite productions
	for (int i = 0, len = grammar2.productions.getSize(); i < len; i++) {
		newGrammar.createProduction(grammar2.productions[i]);
	}

	// add new nonterminal
	char newStart = newGrammar.getNewNonterm();
	newGrammar.addNonterminal(newStart);

	// change start
	newGrammar.start = newStart;

	// add new production
	char newProdRight[3] = { '\0' };
	newProdRight[0] = grammar1.start;
	newProdRight[1] = grammar2.start;
	newGrammar.addProduction(newStart, newProdRight); // S-->S1S2

	return newGrammar;
}

CFG iterate(const CFG& grammar) {
	// copy grammar
	CFG newGrammar = grammar;

	// add new nonterminal
	char newStart = newGrammar.getNewNonterm();
	newGrammar.addNonterminal(newStart);

	// change start
	newGrammar.start = newStart;

	// add new productions
	char newProdRight[3] = { '\0' };
	newProdRight[0] = grammar.start;
	newProdRight[1] = newStart;
	newGrammar.addProduction(newStart, newProdRight); // S0-->SS0
	newGrammar.addProduction(newStart, ""); // S0-->epsilon

	return newGrammar;
}
