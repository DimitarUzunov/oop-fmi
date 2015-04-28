#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template <typename T>
struct LinkedNode {
	T data;
	LinkedNode *next;
	LinkedNode(T data = 0, LinkedNode<T> *next = NULL);
};

template <typename T>
class LinkedQueue {
private:
	LinkedNode<T> *frontNode;
	LinkedNode<T> *backNode;

	void copy(const LinkedQueue<T> &other);
	void destroy();

public:
	LinkedQueue();
	LinkedQueue(T el);
	LinkedQueue(const LinkedQueue<T> &other);
	LinkedQueue &operator=(const LinkedQueue<T> &other);
	~LinkedQueue();

	bool isEmpty() const;
	T front() const;
	int getSize() const;

	void push(T el);
	T pop();
};

#endif
