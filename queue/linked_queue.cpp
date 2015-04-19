#include <climits>
#include <iostream>
#include "linked_queue.h"

LinkedNode::LinkedNode(int data, LinkedNode *next) {
	this->data = data;
	this->next = next;
}

void LinkedQueue::copy(const LinkedQueue &other) {
	frontNode = NULL;
	backNode = NULL;
	
	LinkedNode *tempNode = other.frontNode;

	while (tempNode) {
		push(tempNode->data);
		tempNode = tempNode->next;
	}
}

void LinkedQueue::destroy() {
	while (!isEmpty()) {
		pop();
	}
}

LinkedQueue::LinkedQueue() {
	frontNode = NULL;
	backNode = NULL;
}

LinkedQueue::LinkedQueue(int el) {
	push(el);
}

LinkedQueue::LinkedQueue(const LinkedQueue &other) {
	copy(other);
}

LinkedQueue &LinkedQueue::operator=(const LinkedQueue &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

LinkedQueue::~LinkedQueue() {
	destroy();
}

bool LinkedQueue::isEmpty() const {
	return frontNode == NULL;
}

int LinkedQueue::front() const {
	if (!isEmpty()) {
		return frontNode->data;
	} else {
		std::cout << "Can't get the front element. The queue is empty.\n";
		return -1;
	}
}

int LinkedQueue::getSize() const {
	LinkedNode *tempNode = frontNode;

	int count = 0;
	while (tempNode) {
		tempNode = tempNode->next;
		count++;
	}

	return count;
}

void LinkedQueue::push(int el) {
	LinkedNode *newNode = new LinkedNode(el);
	if (isEmpty()) {
		frontNode = newNode;
		backNode = newNode;
	} else {
		backNode->next = newNode;
		backNode = newNode;
	}
}

int LinkedQueue::pop() {
	if(isEmpty()) {
		std::cout << "Can't pop. The queue is empty.\n";
		return -1;
	}

	if (frontNode->next == NULL) {
		backNode = NULL;
	}

	int data = frontNode->data;

	LinkedNode *tempNode = frontNode;
	frontNode = frontNode->next;
	delete tempNode;

	return data;
}
