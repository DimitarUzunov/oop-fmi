#ifndef TRANSITION_H
#define TRANSITION_H

#include "linked_list.h"

class Transition {
private:
	char state1;
	char inputSym;
	char stackSym;
	char state2;
	int stateId;
	LinkedList<char> toPush;

	bool isDigit(char c) const;

public:
	Transition(char state1 = '\0', char inputSym = '\0', char stackSym = '\0',
						char state2 = '\0', int stateId = 0, const char* toPush = "");

	char getInputSym() const;
	char getStackSym() const;
	int getStateId() const;
	const LinkedList<char>& getToPush() const;
	bool operator<(const Transition& other) const;

	static void swap(Transition& tran1, Transition& tran2);

	friend std::ostream& operator<<(std::ostream& os,
																	const Transition& transition);
};

#endif
