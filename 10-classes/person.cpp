#include <iostream>
#include <cstring>
#include "person.h"

void Person::setName(char **dest, const char *source) {
	if (*dest) {
		delete[] *dest;
	}

	int sourceLen = strlen(source) + 1;
	*dest = new char[sourceLen];
	strncpy(*dest, source, sourceLen);
}

Person::Person() {
	firstName = new char[5];
	const char john[] = "John";
	strncpy(firstName, john, 5);

	lastName = new char[4];
	const char doe[] = "Doe";
	strncpy(lastName, doe, 4);

	age = 18;
	gender = 'm';
}

Person::Person(const char *firstName, const char *lastName,
							int age, char gender) {
								this->firstName = NULL;
								this->lastName = NULL;
								setFirstName(firstName);
								setLastName(lastName);
								this->age = age;
								this->gender = gender;
}

Person::Person(const Person &other) {
	firstName = NULL;
	lastName = NULL;
	setFirstName(other.firstName);
	setLastName(other.lastName);
	age = other.age;
	gender = other.gender;
}

Person::~Person() {
	delete[] firstName;
	firstName = NULL;
	delete[] lastName;
	lastName = NULL;
}

char *Person::getFirstName() const {
	return firstName;
}

char *Person::getLastName() const {
	return lastName;
}

int Person::getAge() const {
	return age;
}

char Person::getGender() const {
	return gender;
}

void Person::setFirstName(const char *firstName) {
	setName(&this->firstName, firstName);
}

void Person::setLastName(const char *lastName) {
	setName(&this->lastName, lastName);
}

void Person::setAge(int age) {
	this->age = age;
}

void Person::setGender(char gender) {
	this->gender = gender;
}
