#include <cstring>
#include "guitar.h"

void Guitar::copy(const Guitar &other) {
	setType(other.type);
	strings = other.strings;
	frets = other.frets;
}

void Guitar::destroy() {
	delete[] type;
	type = NULL;
}

Guitar::Guitar(const char *type, int strings, int frets) {
	this->type = NULL;
	setType(type);
	this->strings = strings;
	this->frets = frets;
}

Guitar::Guitar(const Guitar &other) {
	type = NULL;
	copy(other);
}

Guitar &Guitar::operator=(const Guitar &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Guitar::~Guitar() {
	destroy();
}

const char *Guitar::getType() const {
	return type;
}

int Guitar::getStrings() const {
	return strings;
}

int Guitar::getFrets() const {
	return frets;
}

void Guitar::setType(const char *type) {
	delete[] this->type;

	int typeLen = strlen(type) + 1;
	this->type = new char[typeLen];
	strncpy(this->type, type, typeLen);
}

void Guitar::setStrings(int strings) {
	this->strings = strings;
}

void Guitar::setFrets(int frets) {
	this->frets = frets;
}
