#include <iostream>
#include <cstring>
#include "dog.h"

void Dog::copy(const Dog &other) {
	setName(other.name);
	setBreed(other.breed);
	age = other.age;
}

void Dog::destroy() {
	delete[] name;
	name = NULL;
	delete[] breed;
	breed = NULL;
}

void Dog::setString(char **dest, const char *source) {
	delete[] *dest;

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

Dog::Dog(const Dog &other) {
	name = NULL;
	breed = NULL;
	copy(other);
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Dog::~Dog() {
	destroy();
}

const char *Dog::getName() const {
	return name;
}

const char *Dog::getBreed() const {
	return breed;
}

int Dog::getAge() const {
	return age;
}

void Dog::bark() const {
	std::cout << getName() << " barked!\n";
}

void Dog::setName(const char *name) {
	setString(&this->name, name);
}

void Dog::setBreed(const char *breed) {
	setString(&this->breed, breed);
}

void Dog::setAge(int age) {
	this->age = age;
}
