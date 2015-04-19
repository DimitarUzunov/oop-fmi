#include <iostream>
#include "static_queue.h"

void StaticQueue::moveLeft() {
	for (int i = 1; i < size; i++) {
		elements[i - 1] = elements[i];
	}
}

StaticQueue::StaticQueue() {
	size = 0;
}

bool StaticQueue::isEmpty() const {
	return size == 0;
}

int StaticQueue::front() const {
	if (isEmpty()) {
		std::cout << "Can't get the front element. The queue is empty.\n";
		return -1;
	}

	return elements[0];
}

int StaticQueue::getSize() const {
	return size;
}

void StaticQueue::push(int el) {
	if (size == MAX_SIZE) {
		std::cout << "Can't push. The maximum size is reached.\n";
	} else {
		elements[size++] = el;
	}
}

int StaticQueue::pop() {
	if(isEmpty()) {
		std::cout << "Can't pop. The queue is empty.\n";
		return -1;
	}

	int firstElement = elements[0];
	moveLeft();
	size--;

	return firstElement;
}
