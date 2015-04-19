#include <iostream>
#include "static_stack.h"
#include "dynamic_stack.h"
#include "linked_stack.h"

typedef LinkedStack TestStack;

int main()
{
	TestStack stack;

	for (int i = 1; i <= 10; i++) {
		stack.push(i);
	}

	TestStack copy = stack;

	for (int i = 0; i < 10; i++) {
		std::cout << copy.pop() << '\n';
	}

	for (int i = 0; i < 10; i++) {
		std::cout << stack.pop() << '\n';
	}

	TestStack oneEl(1);
	for (int i = 2; i <= 10; i++) {
		oneEl.push(i);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << oneEl.pop() << '\n';
	}

	return 0;
}
