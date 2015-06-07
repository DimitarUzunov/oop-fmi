#ifndef DYNAMIC_ARRAY_CPP
#define DYNAMIC_ARRAY_CPP

#include <iostream>

template <typename T>
class DynamicArray {
private:
	T* items;
	int size;
	int capacity;

	void copy(const DynamicArray& other);
	void destroy();
	void resize();

public:
	DynamicArray(int capacity = 8);
	DynamicArray(const T* items, int count);
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

	int isEmpty() const;
	int getSize() const;
	T& operator[](int index) const;
	operator const T*() const;

	void pushBack(T item);
	void popBack();
	void insertAt(int index, T item);
	void removeAt(int index);

	friend std::ostream& operator<<(std::ostream& os, const DynamicArray& da);
};

#endif
