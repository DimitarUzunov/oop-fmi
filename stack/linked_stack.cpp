#include <iostream>
#include "linked_stack.h"

LinkedNode::LinkedNode(int data, LinkedNode *next) {
	this->data = data;
	this->next = next;
}

void LinkedStack::copy(const LinkedStack &other) {
	LinkedNode *toCopy = other.topNode;
	LinkedNode *lastCopied = NULL;
	while(toCopy) {
		LinkedNode *newNode = new LinkedNode(toCopy->data);

		if (isEmpty()) {
			topNode = newNode;
			lastCopied = newNode;
		} else {
			lastCopied->next = newNode;
			lastCopied = newNode;
		}

		toCopy = toCopy->next;
	}
}

void LinkedStack::destroy() {
	while(!isEmpty()) {
		pop();
	}
}

LinkedStack::LinkedStack() {
	topNode = NULL;
}

LinkedStack::LinkedStack(int el) {
	topNode = NULL;
	push(el);
}

LinkedStack::LinkedStack(const LinkedStack &other) {
	topNode = NULL;
	copy(other);
}

LinkedStack &LinkedStack::operator=(const LinkedStack &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

LinkedStack::~LinkedStack() {
	destroy();
}

bool LinkedStack::isEmpty() const {
	return topNode == NULL;
}

int LinkedStack::top() const {
	if (isEmpty()) {
		std::cout << "Can't get the top element. The stack is empty.\n";
		return -1;
	}

	return topNode->data;
}

int LinkedStack::getSize() const {
	LinkedNode *tempNode = topNode;

	int count = 0;
	while (!isEmpty()) {
		count++;
		tempNode = tempNode->next;
	}

	return count;
}

void LinkedStack::push(int el) {
	LinkedNode *tempNode = topNode;
	topNode = new LinkedNode(el);
	topNode->next = tempNode;
}

int LinkedStack::pop() {
	if (isEmpty()) {
		std::cout << "Can't pop. The stack is empty.\n";
		return -1;
	}

	int data = topNode->data;

	LinkedNode *tempNode = topNode;
	topNode = topNode->next;
	delete tempNode;

	return data;
}
