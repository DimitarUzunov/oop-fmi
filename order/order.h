#ifndef ORDER_H
#define ORDER_H

#include <iostream>

class Order {
private:
	int id;
	char **items;
	int size;
	int capacity;

	void copy(const Order &other);
	void destroy();
	void resize();

public:
	Order(int id = 0, int capacity = 4);
	Order(const Order &other);
	Order &operator=(const Order &other);
	~Order();

	int getId() const;
	int getSize() const;
	char **getItems() const;

	void addItem(const char *name);
	void cancel();
};

std::ostream &operator<<(std::ostream &os, const Order &order);

#endif
