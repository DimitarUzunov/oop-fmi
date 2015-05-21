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
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

	int isEmpty() const;
	int getSize() const;
	const T& operator[](int index) const;
	operator const char*() const;

	void pushBack(T item);
	void popBack();
	void insertAt(int index, T item);
	void removeAt(int index);

	friend std::ostream& operator<<(std::ostream& os, const DynamicArray& da);
};

template <typename T>
void DynamicArray<T>::copy(const DynamicArray<T>& other) {
	size = other.size;
	capacity = other.capacity;
	items = new T[capacity];
	for (int i = 0; i < size; i++) {
		items[i] = other.items[i];
	}
}

template <typename T>
void DynamicArray<T>::destroy() {
	delete[] items;
}

template <typename T>
void DynamicArray<T>::resize() {
	capacity *= 2;
	T* newItems = new T[capacity];
	for (int i = 0; i < size; i++) {
		newItems[i] = items[i];
	}
	delete[] items;
	items = newItems;
}

template <typename T>
DynamicArray<T>::DynamicArray(int capacity): size(0), capacity(capacity) {
	items = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
	copy(other);
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
	destroy();
}

template <typename T>
int DynamicArray<T>::isEmpty() const {
	return size == 0;
}

template <typename T>
int DynamicArray<T>::getSize() const {
	return size;
}

template <typename T>
const T& DynamicArray<T>::operator[](int index) const {
	return items[index];
}

template <typename T>
DynamicArray<T>::operator const char*() const {
	return items;
}

template <typename T>
void DynamicArray<T>::pushBack(T item) {
	if (size == capacity) resize();
	items[size++] = item;
}

template <typename T>
void DynamicArray<T>::popBack() {
	if (isEmpty()) return;
	size--;
}

template <typename T>
void DynamicArray<T>::insertAt(int index, T item) {
	if (index < 0 || index > size) return;
	if (size == capacity) resize();
	for (int i = size++; i > index; i--) {
		items[i] = items[i - 1];
	}
	items[index] = item;
}

template <typename T>
void DynamicArray<T>::removeAt(int index) {
	if (index < 0 || index >= size) return;
	for (int i = index; i < size - 1; i++) {
		items[i] = items[i + 1];
	}
	size--;
}

inline std::ostream& operator<<(std::ostream& os, const DynamicArray<char>& da) {
	for (int i = 0; i < da.size; i++) {
		os << da[i];
	}
	return os;
}

#endif
