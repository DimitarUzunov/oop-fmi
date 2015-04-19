#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

class DynamicStack {
private:
	int *elements;
	int size;
	int capacity;

	void copy(const DynamicStack &other);
	void destroy();
	void resize();

public:
	DynamicStack(int capacity = 4);
	DynamicStack(const DynamicStack &other);
	DynamicStack &operator=(const DynamicStack &other);
	~DynamicStack();

	bool isEmpty() const;
	int top() const;
	int getSize() const;

	void push(int el);
	int pop();
};

#endif
