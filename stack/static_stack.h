#ifndef STATIC_STACK_H
#define STATIC_STACK_H

const int MAX = 100;

class StaticStack {
private:
	int elements[MAX];
	int size;

public:
	StaticStack();

	bool isEmpty() const;
	int top() const;
	int getSize() const;

	void push(int el);
	int pop();
};

#endif
