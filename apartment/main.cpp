#include <iostream>
#include "apartment.h"
#include "room.h"

int main() {
	Room rooms[] = {Room(50, "living"), Room(15, "bathroom"), Room(30.5, "bedroom")};
	Apartment apartment(rooms, 3);

	std::cout << apartment;
	std::cout << apartment["bedroom"];

	Apartment empty;
	std::cout << (apartment > empty) << '\n';

	return 0;
}
