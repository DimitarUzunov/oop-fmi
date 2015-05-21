#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <iostream>

class Production {
private:
	char left;
	char* right;

	void setRight(const char* right);
	void copy(const Production& other);
	void destroy();

public:
	Production(char left = '\0', const char* right = "");
	Production(const Production& other);
	Production& operator=(const Production& other);
	~Production();

	char getLeft() const;
	const char* getRight() const;
	bool operator==(const Production& other) const;

	friend std::ostream& operator<<(std::ostream& os,
																	const Production& production);
};

#endif
