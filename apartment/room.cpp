#include <iostream>
#include "room.h"

Room::Room(double area, const char *description) {
	this->area = area;
	setDescription(description);
}

double Room::getArea() const {
	return area;
}

const char *Room::getDescription() const {
	return description;
}

void Room::setArea(double area) {
	if (area >= 0) {
		this->area = area;
	} else {
		std::cout << "Area can't be negative.\n";
	}
}

void Room::setDescription(const char *description) {
	strncpy(this->description, description, MAX_DESC);
	this->description[MAX_DESC - 1] = '\0';
}

std::istream &operator>>(std::istream &is, Room &room) {
	is >> room.area;
	is.ignore();
	return is.getline(room.description, MAX_DESC);
}

std::ostream &operator<<(std::ostream &os, const Room &room) {
	return os << "The '" << room.getDescription() << "' room has area = "
		<< room.getArea() << '\n';
}
