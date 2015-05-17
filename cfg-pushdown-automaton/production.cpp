#include <cstring>
#include "production.h"

void Production::setRight(const char* right) {
	this->right = new char[strlen(right) + 1];
	strcpy(this->right, right);
}

void Production::copy(const Production& other) {
	left = other.left;
	setRight(other.right);
}

void Production::destroy() {
	delete[] right;
}

Production::Production(char left, const char* right): left(left) {
	setRight(right);
}

Production::Production(const Production& other) {
	copy(other);
}

Production& Production::operator=(const Production& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Production::~Production() {
	destroy();
}

char Production::getLeft() const {
	return left;
}

const char* Production::getRight() const {
	return right;
}

std::ostream& operator<<(std::ostream& os, const Production& production) {
	return os << production.left << "-->" << production.right;
}
