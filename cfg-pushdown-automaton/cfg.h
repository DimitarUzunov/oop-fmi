#ifndef CFG_H
#define CFG_H

#include <iostream>
#include "dynamic_array.cpp"
#include "production.h"

const int LETTERS = 26;

class CFG {
private:
	DynamicArray<char> nonterminals;
	DynamicArray<char> terminals;
	char start;
	DynamicArray<Production> productions;
	bool isUsedNonterm[LETTERS];

	bool isEps(const char* str) const;
	bool isTerminal(char c) const;
	bool containsTerm(const char* str) const;

	char getNewNonterm() const;
	void addNonterminal(char nonterminal);

	int nontermCountInProd(char nonterm, const Production& prod) const;
	void createProdCombinations(const Production& prod, char nonterm, int count);

public:
	CFG(const char* nonterminals, const char* terminals, char start);

	bool isInCNF() const;

	void addProduction(char left, const char* right);
	void removeProduction(int index);
	void removeLongProductions();
	void removeEpsProductions();
	void removeTerminals();

	friend std::ostream& operator<<(std::ostream& os, const CFG& cfg);
};

#endif
