#include <iostream>
#include "dynamic_stack.h"

void DynamicStack::copy(const DynamicStack &other) {
	capacity = other.capacity;
	size = other.size;

	elements = new int[capacity];
	for (int i = 0; i < size; i++) {
		elements[i] = other.elements[i];
	}
}

void DynamicStack::destroy() {
	delete[] elements;
	elements = NULL;
}

void DynamicStack::resize() {
	capacity *= 2;
	int *newElements = new int[capacity];
	for (int i = 0; i < size; i++) {
		newElements[i] = elements[i];
	}
	delete[] elements;
	elements = newElements;
}

DynamicStack::DynamicStack(int capacity) {
	elements = new int[capacity];
	size = 0;
	this->capacity = capacity;
}

DynamicStack::DynamicStack(const DynamicStack &other) {
	copy(other);
}

DynamicStack &DynamicStack::operator=(const DynamicStack &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

DynamicStack::~DynamicStack() {
	destroy();
}

bool DynamicStack::isEmpty() const {
	return size == 0;
}

int DynamicStack::top() const {
	if (isEmpty()) {
		std::cout << "Can't get the top element. The stack is empty.\n";
		return -1;
	}

	return elements[size - 1];
}

int DynamicStack::getSize() const {
	return size;
}

void DynamicStack::push(int el) {
	if (size == capacity) {
		resize();
	}

	elements[size++] = el;
}

int DynamicStack::pop() {
	if (isEmpty()) {
		std::cout << "Can't pop. The stack is empty.\n";
		return -1;
	}

	return elements[--size];
}
