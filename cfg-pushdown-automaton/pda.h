#ifndef PDA_H
#define PDA_H

#include "dynamic_array.h"
#include "linked_stack.h"
#include "state.h"
#include "cfg.h"

const char EPS = '\0';

class PDA {
private:
	DynamicArray<State> states;
	DynamicArray<char> inputAlpha;
	DynamicArray<char> stackAlpha;
	State* currentState;
	char startState;
	char startStackSym;
	LinkedStack<char> stack;

	static bool found;

	int getStateId(char name) const;

	void initializeStates(const char* states, const char* finalStates);
	void changeState(int id);
	void updateStack(const Transition& transition);
	void pushStack(const Node<char>* toPush);
	void _contains(const char* str, const Node<Transition>* iterator);

public:
	PDA(const char* states, const char* inputAlpha, const char* stackAlpha,
			char startState, char startStackSym, const char* finalStates);
	PDA(const CFG& cfg);

	bool contains(const char* str);

	void addTransition(char state1, char inputSym, char stackSym,
										char state2, const char* toPush);

	void printFinalStates() const;
	friend std::ostream& operator<<(std::ostream& os, const PDA& pda);
};

#endif
