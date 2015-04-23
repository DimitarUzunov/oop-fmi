#include <iostream>
#include "order.h"

int main() {
	Order order;
	order.addItem("iPod");
	order.addItem("iPhone");
	order.addItem("Mac");
	order.cancel();
	order.addItem("iPad");
	order.addItem("iWatch");

	std::cout << order;

	return 0;
}
