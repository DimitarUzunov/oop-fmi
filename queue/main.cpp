#include <iostream>
#include "static_queue.h"
#include "dynamic_queue.h"
#include "linked_queue.h"

typedef LinkedQueue TestQueue;

int main() {
	TestQueue queue;

	for (int i = 1; i <= 10; i++) {
		queue.push(i);
	}

	TestQueue copy = queue;

	for (int i = 0; i < 10; i++) {
		std::cout << copy.pop() << '\n';
	}

	std::cout << "size: " << queue.getSize() << '\n';

	for (int i = 0; i < 10; i++) {
		std::cout << queue.pop() << '\n';
	}

	std::cout << "size: " << queue.getSize() << '\n';

	return 0;
}
