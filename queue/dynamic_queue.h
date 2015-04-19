#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

class DynamicQueue {
private:
	int *elements;
	int size;
	int capacity;

	void copy(const DynamicQueue &other);
	void destroy();
	void resize();
	void moveLeft();

public:
	DynamicQueue(int capacity = 4);
	DynamicQueue(const DynamicQueue &other);
	DynamicQueue &operator=(const DynamicQueue &other);
	~DynamicQueue();

	bool isEmpty() const;
	int front() const;
	int getSize() const;

	void push(int el);
	int pop();
};

#endif
