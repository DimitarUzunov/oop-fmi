#include "dynamic_array.h"
#include "production.h"
#include "state.h"
#include "transition.h"

template <typename T>
void DynamicArray<T>::copy(const DynamicArray& other) {
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
DynamicArray<T>::DynamicArray(const T* items, int count) {
	size = count;
	capacity = count;
	this->items = new T[capacity];
	for (int i = 0; i < count; i++) {
		this->items[i] = items[i];
	}
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) {
	copy(other);
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
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
T& DynamicArray<T>::operator[](int index) const {
	return items[index];
}

template <typename T>
DynamicArray<T>::operator const T*() const {
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

template <typename T>
void DynamicArray<T>::swap(T& item1, T& item2) {
	T& temp = item1;
	item1 = item2;
	item2 = temp;
}

std::ostream& operator<<(std::ostream& os, const DynamicArray<char>& da) {
	for (int i = 0; i < da.size; i++) {
		os << da[i];
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const DynamicArray<Production>& da) {
	for (int i = 0; i < da.size - 1; i++) {
		os << da[i] << '\n';
	}
	return os << da[da.size - 1];
}

std::ostream& operator<<(std::ostream& os, const DynamicArray<State>& da) {
	for (int i = 0; i < da.size - 1; i++) {
		os << da[i] << ", ";
	}
	return os << da[da.size - 1];
}

template class DynamicArray<char>;
template class DynamicArray<Production>;
template class DynamicArray<State>;
template class DynamicArray<Transition*>;
