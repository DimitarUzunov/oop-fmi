#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T>
struct Node {
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = NULL);
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;

	void copy(const LinkedList& other);
	void destroy();

public:
	LinkedList();
	LinkedList(const T& el);
	LinkedList(const T* els, int count);
	LinkedList(const LinkedList& other);
	LinkedList &operator=(const LinkedList& other);
	~LinkedList();

	bool isEmpty() const;
	const Node<T>* getHead() const;

	void insertHead(const T& el);
	void insertTail(const T& el);
	void operator+=(const T& el);
	void insertAt(const T& el, int index);
	void removeHead();
	void removeTail();
	void removeAt(int index);

	friend std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
};

#endif
