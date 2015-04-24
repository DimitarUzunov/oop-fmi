#include <iostream>
#include <cstring>
#include "apartment.h"
#include "room.h"

Apartment::Apartment() {
	rooms[0] = Room();
	count = 1;
}

Apartment::Apartment(const Room rooms[], int count) {
	if (count > 10) {
		count = 10;
	}
	this->count = count;

	for(int i = 0; i < count; i++) {
		this->rooms[i] = rooms[i];
	}
}

int Apartment::getCount() const {
	return count;
}

double Apartment::getArea() const {
	double sum = 0;
	for (int i = 0; i < getCount(); i++) {
		sum += rooms[i].getArea();
	}
	return sum;
}

double Apartment::getAverageArea() const {
	return getArea() / getCount();
}

Room Apartment::getRoomById(int id) const {
	if (id >= getCount() || id < 0) {
		// TODO: throw exception if not found
	}
	return rooms[id];
}

Room Apartment::operator[](const char *description) {
	for (int i = 0; i < count; i++) {
		if (strncmp(rooms[i].getDescription(), description,
				strlen(rooms[i].getDescription()) + 1) == 0) {
			return rooms[i];
		}
	}
	// TODO: throw exception if not found
}

bool operator<(const Apartment &ap1, const Apartment &ap2) {
	return ap1.getAverageArea() < ap2.getAverageArea();
}

bool operator==(const Apartment &ap1, const Apartment &ap2) {
	return ap1.getAverageArea() == ap2.getAverageArea();
}

bool operator>(const Apartment &ap1, const Apartment &ap2) {
	return ap1.getAverageArea() > ap2.getAverageArea();
}

std::istream &operator>>(std::istream &is, Apartment &apartment) {
	is >> apartment.count;
	if (apartment.count > 10) {
		apartment.count = 10;
	}

	for (int i = 0; i < apartment.count; i++) {
		is >> apartment.rooms[i];
	}

	return is;
}

std::ostream &operator<<(std::ostream &os, const Apartment &apartment) {
	os << "The apartment has the following rooms:\n";
	for (int i = 0; i < apartment.getCount(); i++) {
		os << i << ") " << apartment.getRoomById(i) << '\n';
	}
	return os << "The apartment has area = " << apartment.getArea() << '\n';
}
