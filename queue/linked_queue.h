#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template <typename T>
struct LinkedNode {
	T data;
	LinkedNode *next;
	LinkedNode(T data = T(), LinkedNode *next = NULL);
};

template <typename T>
class LinkedQueue {
private:
	LinkedNode<T> *frontNode;
	LinkedNode<T> *backNode;

	void copy(const LinkedQueue &other);
	void destroy();

public:
	LinkedQueue();
	LinkedQueue(T el);
	LinkedQueue(const LinkedQueue &other);
	LinkedQueue &operator=(const LinkedQueue &other);
	~LinkedQueue();

	bool isEmpty() const;
	T front() const;
	int getSize() const;

	void push(T el);
	T pop();
};

#endif
