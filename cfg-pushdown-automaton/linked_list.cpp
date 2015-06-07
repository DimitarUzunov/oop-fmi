#include "linked_list.h"
#include "transition.h"

template <typename T>
Node<T>::Node(const T& data, Node* next): data(data), next(next) {}

template <typename T>
void LinkedList<T>::copy(const LinkedList& other) {
	Node<T>* toCopy = other.head;
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
LinkedList<T>::LinkedList(const T& el): head(NULL), tail(NULL) {
	insertHead(el);
}

template <typename T>
LinkedList<T>::LinkedList(const T* els, int count): head(NULL), tail(NULL) {
	for (int i = 0; i < count; i++) {
		insertTail(els[i]);
	}
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other): head(NULL), tail(NULL) {
	copy(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
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
const Node<T>* LinkedList<T>::getHead() const {
	return head;
}

template <typename T>
void LinkedList<T>::insertHead(const T& el) {
	Node<T>* newNode = new Node<T>(el);

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;
}

template <typename T>
void LinkedList<T>::insertTail(const T& el) {
	Node<T>* newNode = new Node<T>(el);

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		return;
	}

	tail->next = newNode;
	tail = tail->next;
}

template <typename T>
void LinkedList<T>::operator+=(const T& el) {
	return insertTail(el);
}

template <typename T>
void LinkedList<T>::insertAt(const T& el, int index) {
	Node<T>* newNode = new Node<T>(el);

	if (index == 0) {
		insertHead(el);
		return;
	}

	Node<T>* insertAfter = head;
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
void LinkedList<T>::removeHead() {
	if (isEmpty()) return;

	if (head->next == NULL) {
		tail = NULL;
	}

	Node<T>* tempNode = head;
	head = head->next;
	delete tempNode;
}

template <typename T>
void LinkedList<T>::removeTail() {
	if (isEmpty()) return;

	if (head->next == NULL) {
		Node<T>* temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
	}

	Node<T>* prev = head;
	Node<T>* temp = head->next;
	while (temp->next) {
		temp = temp->next;
		prev = prev->next;
	}
	prev->next = NULL;
	tail = prev;
	delete temp;
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
	if (index == 0) removeHead();

	Node<T>* deleteAfter = head;
	Node<T>* toDelete = head->next;
	for (int i = 1; i < index && toDelete->next; i++) {
		deleteAfter = deleteAfter->next;
		toDelete = toDelete->next;
	}

	deleteAfter->next = toDelete->next;

	if (deleteAfter->next == NULL) {
		tail = deleteAfter;
	}

	delete toDelete;
}

std::ostream& operator<<(std::ostream& os, const LinkedList<char>& ll) {
	Node<char>* toPrint = ll.head;
	while (toPrint) {
		os << toPrint->data;
		toPrint = toPrint->next;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const LinkedList<Transition>& ll) {
	Node<Transition>* toPrint = ll.head;
	while (toPrint) {
		os << toPrint->data;
		toPrint = toPrint->next;
		if (toPrint) os << '\n';
	}
	return os;
}

template struct Node<char>;
template class LinkedList<char>;
template struct Node<Transition>;
template class LinkedList<Transition>;
