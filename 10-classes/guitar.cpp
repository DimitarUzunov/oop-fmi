#include <iostream>
#include <cstring>
#include "guitar.h"

Guitar::Guitar() {
	type = new char[9];
	const char acoustic[] = "Acoustic";
	strncpy(type, acoustic, 9);

	strings = 6;
	frets = 19;
}

Guitar::Guitar(const char *type, int strings, int frets) {
	setType(type);
	this->strings = strings;
	this->frets = frets;
}

char *Guitar::getType() const {
	return type;
}

int Guitar::getStrings() const {
	return strings;
}

int Guitar::getFrets() const {
	return frets;
}

void Guitar::setType(const char *type) {
	if (this->type) {
		delete[] this->type;
	}

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

Guitar::~Guitar() {
	delete[] type;
	type = NULL;
}

int main()
{
	char electric[] = "Electric";
	Guitar guitar(electric, 6, 22);

	std::cout << guitar.getType() << '\n';
	guitar.setType("Acoustic");
	std::cout << guitar.getType() << '\n';
	std::cout << guitar.getStrings() << '\n';
	std::cout << guitar.getFrets() << '\n';

	return 0;
}
