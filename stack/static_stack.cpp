#include <iostream>
#include "static_stack.h"

StaticStack::StaticStack() {
	size = 0;
}

bool StaticStack::isEmpty() const {
	return size == 0;
}

int StaticStack::top() const {
	if (isEmpty()) {
		std::cout << "Can't get the top element. The stack is empty.\n";
		return -1;
	}

	return elements[size - 1];
}

int StaticStack::getSize() const {
	return size;
}

void StaticStack::push(int el) {
	if (size == MAX) {
		std::cout << "Can't push. The maximum size is reached.\n";
	} else {
		elements[size++] = el;
	}
}

int StaticStack::pop() {
	if (isEmpty()) {
		std::cout << "Can't pop. The stack is empty.\n";
		return -1;
	}

	return elements[--size];
}
