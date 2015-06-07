#include "transition.h"

Transition::Transition(char state1, char inputSym, char stackSym,
											char state2, int stateId, const char* toPush)
											: state1(state1), inputSym(inputSym), stackSym(stackSym),
											state2(state2), stateId(stateId),
											toPush(toPush, strlen(toPush)) {}

char Transition::getInputSym() const {
	return inputSym;
}

char Transition::getStackSym() const {
	return stackSym;
}

int Transition::getStateId() const {
	return stateId;
}

const LinkedList<char>& Transition::getToPush() const {
	return toPush;
}

std::ostream& operator<<(std::ostream& os, const Transition& transition) {
	return os << '('<< transition.state1 << ", "
						<< transition.inputSym << ", "
						<< transition.stackSym << ", "
						<< transition.state2 << ", "
						<< transition.toPush << ')';
}
