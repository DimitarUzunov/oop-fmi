#include "state.h"

State::State(int id, char name, bool isFinal)
						: id(id), name(name), isFinal(isFinal) {}

int State::getId() const {
	return id;
}

char State::getName() const {
	return name;
}

bool State::getIsFinal() const {
	return isFinal;
}

const LinkedList<Transition>& State::getTransitions() const {
	return transitions;
}

void State::addTransition(char state1, char inputSym, char stackSym,
													char state2, int stateId, const char* toPush) {
	transitions.insertTail(Transition(state1, inputSym, stackSym,
												state2, stateId, toPush));
}

void State::printTransitions() {
	if (transitions.isEmpty()) {
		std::cout << "No transitions for state " << name;
		return;
	}
	std::cout << transitions;
}

std::ostream& operator<<(std::ostream& os, const State& state) {
	return os << (state.isFinal ? "*" : "") << state.name;
}
