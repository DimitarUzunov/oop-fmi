#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

const int MAX_SIZE = 100;

class StaticQueue {
private:
	int elements[MAX_SIZE];
	int size;

	void moveLeft();

public:
	StaticQueue();

	bool isEmpty() const;
	int front() const;
	int getSize() const;

	void push(int el);
	int pop();
};

#endif
