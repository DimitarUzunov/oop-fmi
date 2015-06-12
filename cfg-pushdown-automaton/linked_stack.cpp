#include "linked_stack.h"

template <typename T>
LinkedNode<T>::LinkedNode(const T& data, LinkedNode* next)
													: data(data), next(next) {}

template <typename T>
void LinkedStack<T>::copy(const LinkedStack &other) {
	LinkedNode<T>* toCopy = other.topNode;
	LinkedNode<T>* lastCopied = NULL;
	while(toCopy) {
		LinkedNode<T>* newNode = new LinkedNode<T>(toCopy->data);

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

template <typename T>
void LinkedStack<T>::destroy() {
	while(!isEmpty()) {
		pop();
	}
}

template <typename T>
LinkedStack<T>::LinkedStack(): topNode(NULL) {}

template <typename T>
LinkedStack<T>::LinkedStack(const T& el): topNode(NULL) {
	push(el);
}

template <typename T>
LinkedStack<T>::LinkedStack(const T* els, int count) {
	for (int i = 0; i < count; i++) {
		push(els[i]);
	}
}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack& other): topNode(NULL) {
	copy(other);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
	destroy();
}

template <typename T>
bool LinkedStack<T>::isEmpty() const {
	return topNode == NULL;
}

template <typename T>
T LinkedStack<T>::top() const {
	if (isEmpty()) return T();

	return topNode->data;
}

template <typename T>
int LinkedStack<T>::getSize() const {
	LinkedNode<T>* tempNode = topNode;

	int count = 0;
	while (tempNode) {
		count++;
		tempNode = tempNode->next;
	}

	return count;
}

template <typename T>
void LinkedStack<T>::push(const T& el) {
	LinkedNode<T>* tempNode = topNode;
	topNode = new LinkedNode<T>(el);
	topNode->next = tempNode;
}

template <typename T>
void LinkedStack<T>::pop() {
	if (isEmpty()) return;

	LinkedNode<T>* tempNode = topNode;
	topNode = topNode->next;
	delete tempNode;
}

std::ostream& operator<<(std::ostream& os, const LinkedStack<char>& ls) {
	LinkedNode<char>* toPrint = ls.topNode;
	while (toPrint) {
		os << toPrint->data;
		toPrint = toPrint->next;
	}
	return os;
}

template struct LinkedNode<char>;
template class LinkedStack<char>;
