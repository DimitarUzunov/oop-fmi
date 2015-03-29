#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
private:
	int sidesCount;
	double sideLength;

	void printError() const;

public:
	Polygon(int sidesCount = 3, double sideLength = 1);

	int getSidesCount() const;
	double getSideLength() const;
	bool isValid() const;
	double getPerimeter() const;
	double getArea() const;

	void setSidesCount(int sidesCount);
	void setSideLength(int sideLength);
};

#endif
