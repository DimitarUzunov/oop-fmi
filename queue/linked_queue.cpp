#include <iostream>
#include "linked_queue.h"

template <typename T>
LinkedNode<T>::LinkedNode(T data, LinkedNode<T> *next) {
	this->data = data;
	this->next = next;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T> &other) {
	LinkedNode<T> *tempNode = other.frontNode;

	while (tempNode) {
		push(tempNode->data);
		tempNode = tempNode->next;
	}
}

template <typename T>
void LinkedQueue<T>::destroy() {
	while (!isEmpty()) {
		pop();
	}
}

template <typename T>
LinkedQueue<T>::LinkedQueue() {
	frontNode = NULL;
	backNode = NULL;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(T el) {
	frontNode = NULL;
	backNode = NULL;
	push(el);
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T> &other) {
	frontNode = NULL;
	backNode = NULL;
	copy(other);
}

template <typename T>
LinkedQueue<T> &LinkedQueue<T>::operator=(const LinkedQueue<T> &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
	destroy();
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
	return frontNode == NULL;
}

template <typename T>
T LinkedQueue<T>::front() const {
	if (isEmpty()) {
		std::cout << "Can't get the front element. The queue is empty.\n";
		return -1;
	}

	return frontNode->data;
}

template <typename T>
int LinkedQueue<T>::getSize() const {
	LinkedNode<T> *tempNode = frontNode;

	int count = 0;
	while (tempNode) {
		tempNode = tempNode->next;
		count++;
	}

	return count;
}

template <typename T>
void LinkedQueue<T>::push(T el) {
	LinkedNode<T> *newNode = new LinkedNode<T>(el);
	if (isEmpty()) {
		frontNode = newNode;
		backNode = newNode;
	} else {
		backNode->next = newNode;
		backNode = newNode;
	}
}

template <typename T>
T LinkedQueue<T>::pop() {
	if(isEmpty()) {
		std::cout << "Can't pop. The queue is empty.\n";
		return -1;
	}

	if (frontNode->next == NULL) {
		backNode = NULL;
	}

	int data = frontNode->data;

	LinkedNode<T> *tempNode = frontNode;
	frontNode = frontNode->next;
	delete tempNode;

	return data;
}
