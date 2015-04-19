#ifndef LINKED_STACK_H
#define LINKED_STACK_H

struct LinkedNode {
	int data;
	LinkedNode *next;
	LinkedNode(int data = 0, LinkedNode *next = NULL);
};

class LinkedStack {
private:
	LinkedNode *topNode;

	void copy(const LinkedStack &other);
	void destroy();

public:
	LinkedStack();
	LinkedStack(int el);
	LinkedStack(const LinkedStack &other);
	LinkedStack &operator=(const LinkedStack &other);
	~LinkedStack();

	bool isEmpty() const;
	int top() const;
	int getSize() const;

	void push(int el);
	int pop();
};

#endif
