#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <iostream>

template <typename T>
struct LinkedNode {
	T data;
	LinkedNode *next;
	LinkedNode(const T& data = T(), LinkedNode *next = NULL);
};

template <typename T>
class LinkedStack {
private:
	LinkedNode<T>* topNode;

	void copy(const LinkedStack &other);
	void destroy();

public:
	LinkedStack();
	LinkedStack(const T& el);
	LinkedStack(const T* els, int count);
	LinkedStack(const LinkedStack& other);
	LinkedStack& operator=(const LinkedStack& other);
	~LinkedStack();

	bool isEmpty() const;
	T top() const;
	int getSize() const;

	void push(const T& el);
	void pop();

	friend std::ostream& operator<<(std::ostream& os, const LinkedStack& ls);
};

#endif
