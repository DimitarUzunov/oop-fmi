#ifndef STATE_H
#define STATE_H

#include "linked_list.h"
#include "transition.h"

class State {
private:
	int id;
	char name;
	bool isFinal;
	LinkedList<Transition> transitions;

public:
	State(int id = 0, char name = '\0', bool isFinal = false);

	int getId() const;
	char getName() const;
	bool getIsFinal() const;
	const LinkedList<Transition>& getTransitions() const;

	void addTransition(char state1, char inputSym, char stackSym,
										char state2, int stateId, const char* toPush);

	void printTransitions();
	friend std::ostream& operator<<(std::ostream& os, const State& state);
};

#endif
