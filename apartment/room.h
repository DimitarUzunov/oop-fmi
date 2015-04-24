#ifndef ROOM_H
#define ROOM_H

#include <iostream>

const int MAX_DESC = 30;

class Room {
private:
	double area;
	char description[MAX_DESC];

public:
	Room(double area = 0, const char *description = "Empty");

	double getArea() const;
	const char *getDescription() const;

	void setArea(double area);
	void setDescription(const char *description);

	friend std::istream &operator>>(std::istream &is, Room &room);
};

std::ostream &operator<<(std::ostream &os, const Room &room);

#endif
