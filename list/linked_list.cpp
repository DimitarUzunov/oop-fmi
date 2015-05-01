#include <iostream>
#include "linked_list.h"

template <typename T>
Node<T>::Node(T data, Node *next): data(data), next(next) {}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T> &other) {
	Node<T> *toCopy = other.head;
	while (toCopy) {
		insertTail(toCopy->data);
		toCopy = toCopy->next;
	}
}

template <typename T>
void LinkedList<T>::destroy() {
	while (head) {
		removeHead();
	}
}

template <typename T>
LinkedList<T>::LinkedList(): head(NULL), tail(NULL) {}

template <typename T>
LinkedList<T>::LinkedList(T el): head(NULL), tail(NULL) {
	insertHead(el);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other): head(NULL), tail(NULL) {
	copy(other);
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	destroy();
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
	return head == NULL;
}

template <typename T>
T LinkedList<T>::getAt(int index) const {
	if (isEmpty()) {
		return -1;
	}

	Node<T> *toReturn = head;
	for (int i = 0; i < index && toReturn->next; i++) {
		toReturn = toReturn->next;
	}

	return toReturn->data;
}

template <typename T>
T LinkedList<T>::operator[](int index) const {
	return getAt(index);
}

template <typename T>
int LinkedList<T>::search(T el) const {
	int index = 0;
	Node<T> *temp = head;
	while (temp) {
		if (temp->data == el) {
			return index;
		}
		temp = temp->next;
		index++;
	}

	return -1;
}

template <typename T>
void LinkedList<T>::print() const {
	if (isEmpty()) {
		std::cout << "The list is empty.\n";
		return;
	}

	Node<T> *toPrint = head;
	while (toPrint) {
		std::cout << toPrint->data << ' ';
		toPrint = toPrint->next;
	}
	std::cout << '\n';
}

template <typename T>
void LinkedList<T>::insertHead(T el) {
	Node<T> *newNode = new Node<T>(el);

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;
}

template <typename T>
void LinkedList<T>::insertTail(T el) {
	Node<T> *newNode = new Node<T>(el);

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		return;
	}

	tail->next = newNode;
	tail = tail->next;
}

template <typename T>
void LinkedList<T>::operator+=(T el) {
	return insertTail(el);
}

template <typename T>
void LinkedList<T>::insertAt(T el, int index) {
	Node<T> *newNode = new Node<T>(el);

	if (index == 0) {
		insertHead(el);
		return;
	}

	Node<T> *insertAfter = head;
	for (int i = 1; i < index && insertAfter->next; i++) {
		insertAfter = insertAfter->next;
	}
	newNode->next = insertAfter->next;

	if (newNode->next == NULL) {
		tail = newNode;
	}

	insertAfter->next = newNode;
}

template <typename T>
T LinkedList<T>::removeHead() {
	if (isEmpty()) {
		return -1;
	}

	if (head->next == NULL) {
		tail = NULL;
	}

	T data = head->data;

	Node<T> *tempNode = head;
	head = head->next;
	delete tempNode;

	return data;
}

template <typename T>
T LinkedList<T>::removeTail() {
	if (isEmpty()) {
		return -1;
	}

	if (head->next == NULL) {
		Node<T> *temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
	}

	T data = tail->data;

	Node<T> *prev = head;
	Node<T> *temp = head->next;
	while (temp->next) {
		temp = temp->next;
		prev = prev->next;
	}
	prev->next = NULL;
	tail = prev;
	delete temp;

	return data;
}

template <typename T>
T LinkedList<T>::removeAt(int index) {
	if (index == 0) {
		return removeHead();
	}

	Node<T> *deleteAfter = head;
	Node<T> *toDelete = head->next;
	for (int i = 1; i < index && toDelete->next; i++) {
		deleteAfter = deleteAfter->next;
		toDelete = toDelete->next;
	}

	T data = toDelete->data;

	deleteAfter->next = toDelete->next;

	if (deleteAfter->next == NULL) {
		tail = deleteAfter;
	}

	delete toDelete;

	return data;
}
