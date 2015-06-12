#ifndef CFG_H
#define CFG_H

#include <iostream>
#include "dynamic_array.h"
#include "production.h"
#include "pda.h"

// TODO: make them static members of the class
const int NONTERMS = 26;
const int TERMS = 35;

class CFG {
private:
	DynamicArray<char> nonterminals;
	DynamicArray<char> terminals;
	char start;
	DynamicArray<Production> productions;
	bool isUsedNonterm[NONTERMS];
	bool isUsedTerm[TERMS];

	bool isEps(const char* str) const;
	bool isTerminal(char c) const;
	bool containsTerm(const char* str) const;
	bool productionExists(char left, const char* right) const;
	void addTerminal(char terminal);
	void createProduction(const Production& production);

	char getNewNonterm() const;
	void addNonterminal(char nonterminal);

	int nontermCountInProd(char nonterm, const Production& prod) const;
	void createProdCombinations(const Production& prod, char nonterm, int count);

	void initializeNonterms(const char* nonterminals);
	void initializeTerms(const char* terminals);

public:
	CFG(const char* nonterminals, const char* terminals, char start);
	CFG(const PDA& pda);

	bool isInCNF() const;
	bool contains(const char* str) const;
	const DynamicArray<char>& getTerminals() const;
	const DynamicArray<char>& getNonterminals() const;
	const DynamicArray<Production>& getProductions() const;
	char getStart() const;

	void addProduction(char left, const char* right);
	void removeProduction(int index);

	void removeLongProductions();
	void removeEpsProductions();
	void removeTerminals();

	friend std::ostream& operator<<(std::ostream& os, const CFG& cfg);

	friend CFG unite(const CFG& grammar1, const CFG& grammar2);
	friend CFG concatenate(const CFG& grammar1, const CFG& grammar2);
	friend CFG iterate(const CFG& grammar);
};

#endif
