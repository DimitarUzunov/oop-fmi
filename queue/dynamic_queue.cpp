#include <iostream>
#include "dynamic_queue.h"

void DynamicQueue::copy(const DynamicQueue &other) {
	capacity = other.capacity;
	size = other.size;

	elements = new int[capacity];
	for (int i = 0; i < size; i++) {
		elements[i] = other.elements[i];
	}
}

void DynamicQueue::destroy() {
	delete[] elements;
	elements = NULL;
}

void DynamicQueue::resize() {
	capacity *= 1.5;
	int *newElements = new int[capacity];
	for (int i = 0; i < size; i++) {
		newElements[i] = elements[i];
	}
	delete[] elements;
	elements = newElements;
}

void DynamicQueue::moveLeft() {
	for (int i = 1; i < size; i++) {
		elements[i - 1] = elements[i];
	}
}

DynamicQueue::DynamicQueue(int capacity) {
	elements = new int[capacity];
	size = 0;
	this->capacity = capacity;
}

DynamicQueue::DynamicQueue(const DynamicQueue &other) {
	copy(other);
}

DynamicQueue &DynamicQueue::operator=(const DynamicQueue &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

DynamicQueue::~DynamicQueue() {
	destroy();
}

bool DynamicQueue::isEmpty() const {
	return size == 0;
}

int DynamicQueue::front() const {
	if (isEmpty()) {
		std::cout << "Can't get the front element. The queue is empty.\n";
		return -1;
	}

	return elements[0];
}

int DynamicQueue::getSize() const {
	return size;
}

void DynamicQueue::push(int el) {
	if (size == capacity) {
		resize();
	}

	elements[size++] = el;
}

int DynamicQueue::pop() {
	if(isEmpty()) {
		std::cout << "Can't pop. The queue is empty.\n";
		return -1;
	}

	int firstElement = elements[0];
	moveLeft();
	size--;

	return firstElement;
}
