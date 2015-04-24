#include <iostream>
#include "order.h"

int main() {
	const char *items[] = {"iPod", "iPhone", "Mac"};
	Order order(1, items, 3);

	std::cout << order;

	Order wishList = order;
	order.cancel();
	wishList.setId(2);
	wishList.addItem("iPad");
	wishList.addItem("iWatch");

	std::cout << wishList;

	return 0;
}
