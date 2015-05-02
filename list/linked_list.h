#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
struct Node {
	T data;
	Node *next;
	Node(T data = T(), Node *next = NULL);
};

template <typename T>
class LinkedList {
private:
	Node<T> *head;
	Node<T> *tail;

	void copy(const LinkedList &other);
	void destroy();

public:
	LinkedList();
	LinkedList(T el);
	LinkedList(const LinkedList &other);
	LinkedList &operator=(const LinkedList &other);
	~LinkedList();

	bool isEmpty() const;
	T getAt(int index) const;
	T operator[](int index) const;
	int search(T el) const;
	void print() const;

	void insertHead(T el);
	void insertTail(T el);
	void operator+=(T el);
	void insertAt(T el, int index);
	T removeHead();
	T removeTail();
	T removeAt(int index);
};

#endif
