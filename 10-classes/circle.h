#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double radius;

public:
	Circle(double radius = 1);

	double getRadius() const;
	double getPerimeter() const;
	double getArea() const;

	void setRadius(double radius);
};

#endif
