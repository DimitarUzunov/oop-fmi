#include <iostream>
#include <cstring>
#include "order.h"

void Order::copy(const Order &other) {
	id = other.id;
	size = 0;
	capacity = other.capacity;
	items = new char*[capacity];
	for (int i = 0; i < other.size; i++) {
		addItem(other.items[i]);
	}
}

void Order::destroy() {
	cancel();
	delete[] items;
	items = NULL;
}

void Order::resize() {
	capacity *= 2;
	char **newItems = new char*[capacity];
	for (int i = 0; i < size; i++) {
		newItems[i] = items[i];
	}
	delete[] items;
	items = newItems;
}

Order::Order(int id, int capacity) {
	this->id = id;
	items = new char*[capacity];
	size = 0;
	this->capacity = capacity;
}

Order::Order(int id, const char **items, int count) {
	this->id = id;
	size = 0;
	capacity = count;
	this->items = new char*[capacity];
	for (int i = 0; i < capacity; i++) {
		addItem(items[i]);
	}
}

Order::Order(const Order &other) {
	copy(other);
}

Order &Order::operator=(const Order &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Order::~Order() {
	destroy();
}

int Order::getId() const {
	return id;
}

int Order::getSize() const {
	return size;
}

char **Order::getItems() const {
	return items;
}

void Order::setId(int id) {
	this->id = id;
}

void Order::addItem(const char *name) {
	if (size == capacity) {
		resize();
	}

	items[size] = new char[strlen(name) + 1];
	strcpy(items[size++], name);
}

void Order::cancel() {
	for (int i = 0; i < size; i++) {
		delete[] items[i];
	}
	size = 0;
}

std::ostream &operator<<(std::ostream &os, const Order &order) {
	if (order.getSize() == 0) {
		os << "Order with id '" << order.getId() << "' has no items.\n";
		return os;
	}

	os << "Order with id '" << order.getId() << "' has the following items:\n";
	for (int i = 0; i < order.getSize(); i++) {
		os << order.getItems()[i] << '\n';
	}
	return os;
}
