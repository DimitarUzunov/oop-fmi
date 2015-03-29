#include <iostream>
#include "dog.h"

void Dog::setStringField(char **dest, const char *source) {
	if (*dest) {
		delete[] *dest;
	}

	int sourceLen = strlen(source) + 1;
	*dest = new char[sourceLen];
	strncpy(*dest, source, sourceLen);
}

Dog::Dog(const char *name, const char *breed, int age) {
	this->name = NULL;
	this->breed = NULL;
	setName(name);
	setBreed(breed);
	this->age = age;
}

Dog::~Dog() {
	delete[] name;
	name = NULL;
	delete[] breed;
	breed = NULL;
}

char *Dog::getName() const {
	return name;
}

char *Dog::getBreed() const {
	return breed;
}

int Dog::getAge() const {
	return age;
}

void Dog::bark() const {
	std::cout << getName() << " barked!\n";
}

void Dog::setName(const char *name) {
	setStringField(&this->name, name);
}

void Dog::setBreed(const char *breed) {
	setStringField(&this->breed, breed);
}

void Dog::setAge(int age) {
	this->age = age;
}
