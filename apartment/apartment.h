#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include "room.h"

const int MAX_ROOMS = 10;

class Apartment {
private:
	Room rooms[MAX_ROOMS];
	int count;

public:
	Apartment();
	Apartment(const Room rooms[], int count);

	int getCount() const;
	double getArea() const;
	double getAverageArea() const;
	Room getRoomById(int id) const;
	Room operator[](const char *description);

	friend std::istream &operator>>(std::istream &is, Apartment &apartment);
};

std::ostream &operator<<(std::ostream &os, const Apartment &apartment);
bool operator<(const Apartment &ap1, const Apartment &ap2);
bool operator==(const Apartment &ap1, const Apartment &ap2);
bool operator>(const Apartment &ap1, const Apartment &ap2);

#endif
