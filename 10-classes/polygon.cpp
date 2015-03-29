#include <iostream>
#include <cmath>
#include "polygon.h"

void Polygon::printError() const {
	std::cout << "The polygon is not valid.\n";
}

Polygon::Polygon(int sidesCount, double sideLength) {
	this->sidesCount = sidesCount;
	this->sideLength = sideLength;
}

int Polygon::getSidesCount() const {
	return sidesCount;
}

double Polygon::getSideLength() const {
	return sideLength;
}

bool Polygon::isValid() const {
	return sidesCount > 2 && sideLength > 0;
}

double Polygon::getPerimeter() const {
	if (!isValid()) {
		printError();
		return -1;
	}
	return sidesCount * sideLength;
}

double Polygon::getArea() const {
	if (!isValid()) {
		printError();
		return -1;
	}

	int sidesCount = getSidesCount();
	double sideLength = getSideLength();
	double centerAngle = 2 * M_PI / sidesCount;
	double angle = M_PI_2 - centerAngle / 2;

	return sidesCount * pow((sin(angle) * sideLength), 2) / (sin(centerAngle) * 2);
}

void Polygon::setSidesCount(int sidesCount) {
	this->sidesCount = sidesCount;
}

void Polygon::setSideLength(int sideLength) {
	this->sideLength = sideLength;
}
