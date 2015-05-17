#include <cstring>
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

char CFG::getNewNonterm() const {
	for (int i = 0; i < LETTERS; i++) {
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
		char currentLeft = productions[i].getLeft();
		char currentRight = right[0];
		int rightLen = strlen(right);

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
			}
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
				term[0] = *right;
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

void CFG::createProdCombinations(const Production& prod,
																char nonterm, int count) {
	char left = prod.getLeft();
	const char* right = prod.getRight();
	int rightLen = strlen(right);

	int combsCount = (1 << count) - 1; // combsCount = 2^count - 1
	for (int i = 0; i < combsCount; i++) {
		int nthNonterm = 0;
		char newRight[3] = { '\0' };
		int newPos = 0;

		// construct right side of the new production
		for (int j = 0; j < rightLen; j++) {
			if (right[j] == nonterm) {
				if (i & (1 << nthNonterm++)) newRight[newPos++] = right[j];
			} else {
				newRight[newPos++] = right[j];
			}
		}

		// add new production
		addProduction(left, newRight);
	}
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

		// iterate over all productions and generate combinations
		int prodCount = productions.getSize();
		for (int i = 0; i < prodCount; i++) {
			// get number of occurrences of epsilon nonterminal in current production
			int count = nontermCountInProd(epsProdLeft, productions[i]);

			// add new productions if nonterminal occurs in current production
			if (count) createProdCombinations(productions[i], epsProdLeft, count);
		}
	}
}

CFG::CFG(const char* nonterminals, const char* terminals, char start)
				: terminals(terminals, strlen(terminals)), start(start) {
	for (int i = 0; i < LETTERS; i++) isUsedNonterm[i] = false;
	for (int i = 0, len = strlen(nonterminals); i < len; i++) {
		addNonterminal(nonterminals[i]);
	}
}

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
