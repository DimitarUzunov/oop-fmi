#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

struct LinkedNode {
	int data;
	LinkedNode *next;
	LinkedNode(int data = 0, LinkedNode *next = NULL);
};

class LinkedQueue {
private:
	LinkedNode *frontNode;
	LinkedNode *backNode;

	void copy(const LinkedQueue &other);
	void destroy();

public:
	LinkedQueue();
	LinkedQueue(int el);
	LinkedQueue(const LinkedQueue &other);
	LinkedQueue &operator=(const LinkedQueue &other);
	~LinkedQueue();

	bool isEmpty() const;
	int front() const;
	int getSize() const;

	void push(int el);
	int pop();
};

#endif
