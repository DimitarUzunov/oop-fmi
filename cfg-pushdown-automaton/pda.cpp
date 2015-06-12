#include <cstring> // strlen, strchr
#include "pda.h"
#include "cfg.h"

bool PDA::found = false;

int PDA::getStateId(char name) const {
	for (int i = 0, count = states.getSize(); i < count; i++) {
		if (name == states[i].getName()) return i;
	}
	return -1;
}

void PDA::initializeStates(const char* states, const char* finalStates) {
	for (int i = 0, count = strlen(states); i < count; i++) {
		this->states.pushBack(State(i, states[i],
																(bool)strchr(finalStates, states[i])));
	}
}

void PDA::changeState(int id) {
	if (id != currentState->getId()) {
		currentState = &states[id];
	}
}

// update stack on transition
void PDA::updateStack(const Transition& transition) {
	stack.pop();
	const Node<char>* toPush = transition.getToPush().getHead();
	pushStack(toPush);
}

void PDA::pushStack(const Node<char>* toPush) {
	if (toPush == NULL) return;
	pushStack(toPush->next);
	stack.push(toPush->data);
}

void PDA::_contains(const char* str, const Node<Transition>* iterator) {
	// std::cout << *str << ' ' << stack << '\n';
	// const char* str1 = str;
	if (*str == EPS && stack.isEmpty()) found = true;
	// if (currentState->getIsFinal() && *str == EPS) found = true;
	// if (strlen(str) < stack.getSize()) {
	// 	return;
	// }

	while (iterator) {
		const Transition& transition = iterator->data;
		if (transition.getInputSym() == *str &&
				stack.top() == transition.getStackSym()) { // transition on input
			updateStack(transition);
			changeState(transition.getStateId());
			_contains(str + 1, currentState->getTransitions().getHead());
		}
		else if (transition.getInputSym() == EPS &&
						stack.top() == transition.getStackSym()) { // epsilon transition
			updateStack(transition);
			changeState(transition.getStateId());
			_contains(str, currentState->getTransitions().getHead());
		}
		iterator = iterator->next;
	}
}

void PDA::sortTransitions() {
	for (int i = 0, len = transitions.getSize(); i < len - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < len; j++) {
			if (*transitions[j] < *transitions[minIndex]) minIndex = j;
		}
		if (i != minIndex) {
			Transition::swap(*transitions[i], *transitions[minIndex]);
			DynamicArray<Transition*>::swap(transitions[i], transitions[minIndex]);
		}
	}
}

PDA::PDA(const char* states, const char* inputAlpha, const char* stackAlpha,
				char startState, char startStackSym, const char* finalStates)
				: inputAlpha(inputAlpha, strlen(inputAlpha)),
					stackAlpha(stackAlpha, strlen(stackAlpha)),
					startState(startState),
					startStackSym(startStackSym) {
	initializeStates(states, finalStates);
	currentState = &this->states[getStateId(startState)];
	stack.push(startStackSym);
}

PDA::PDA(const CFG& cfg): inputAlpha(cfg.getTerminals()),
													stackAlpha(cfg.getNonterminals()),
													startState('Q'),
													startStackSym(cfg.getStart()) {
	// initialize state
	states.pushBack(State(0, startState, 0));
	currentState = &states[0];

	// initialize stack with start symbol of grammar
	stack.push(startStackSym);

	// add terminals to stack alphabet and add transition for each terminal
	for (int i = 0, count = cfg.getTerminals().getSize(); i < count; i++) {
		char terminal = cfg.getTerminals()[i];
		stackAlpha.pushBack(terminal);
		addTransition(startState, terminal, terminal, startState, "");
	}

	// add transition for each production
	for (int i = 0, count = cfg.getProductions().getSize(); i < count; i++) {
		addTransition(startState, EPS, cfg.getProductions()[i].getLeft(),
									startState, cfg.getProductions()[i].getRight());
	}
}

const DynamicArray<State>& PDA::getStates() const {
	return states;
}

const DynamicArray<char>& PDA::getInputAlpha() const {
	return inputAlpha;
}

const DynamicArray<char>& PDA::getStackAlpha() const {
	return stackAlpha;
}

char PDA::getStartStackSym() const {
	return startStackSym;
}

bool PDA::contains(const char* str) {
	found = false;
	sortTransitions();
	//_contains(str, currentState->getTransitions().getHead());
	return found;
}

void PDA::addTransition(char state1, char inputSym, char stackSym,
												char state2, const char* toPush) {
	Transition* tran = states[getStateId(state1)]
														.addTransition(state1, inputSym, stackSym,
																					state2, getStateId(state2), toPush);
	transitions.pushBack(tran);
}

void PDA::printFinalStates() const {
	int statesCount = states.getSize();
	for (int i = 0; i < statesCount - 1; i++) {
		if (states[i].getIsFinal()) std::cout << states[i] << ", ";
	}
	if (states[statesCount - 1].getIsFinal()) {
		std::cout << states[statesCount - 1];
	}
}

std::ostream& operator<<(std::ostream& os, const PDA& pda) {
	os << "States: " << pda.states << '\n'
		<< "Input alphabet: " << pda.inputAlpha << '\n'
		<< "Stack alphabet: " << pda.stackAlpha << '\n'
		<< "Start state: " << pda.startState << '\n'
		<< "Start stack symbol: " << pda.startStackSym << '\n'
		<< "Final states: "; pda.printFinalStates(); os << '\n'
		<< "Transitions:\n";

	int statesCount = pda.states.getSize();
	for (int i = 0; i < statesCount - 1; i++) {
		pda.states[i].printTransitions(); os << '\n';
	}
	pda.states[statesCount - 1].printTransitions();
	return os;
}
