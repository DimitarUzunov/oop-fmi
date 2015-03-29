#include <cmath>
#include "circle.h"

Circle::Circle(double radius) {
	this->radius = radius;
}

double Circle::getRadius() const {
	return radius;
}

double Circle::getPerimeter() const {
	return 2 * M_PI * radius;
}

double Circle::getArea() const {
	return M_PI * radius * radius;
}

void Circle::setRadius(double radius) {
	this->radius = radius;
}
