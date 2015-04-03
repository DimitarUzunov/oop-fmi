#include <cstring>
#include "person.h"

void Person::copy(const Person &other) {
	setFirstName(other.firstName);
	setLastName(other.lastName);
	age = other.age;
	gender = other.gender;
}

void Person::destroy() {
	delete[] firstName;
	firstName = NULL;
	delete[] lastName;
	lastName = NULL;
}

void Person::setString(char **dest, const char *source) {
	delete[] *dest;

	int sourceLen = strlen(source) + 1;
	*dest = new char[sourceLen];
	strncpy(*dest, source, sourceLen);
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
	copy(other);
}

Person &Person::operator=(const Person &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Person::~Person() {
	destroy();
}

const char *Person::getFirstName() const {
	return firstName;
}

const char *Person::getLastName() const {
	return lastName;
}

int Person::getAge() const {
	return age;
}

char Person::getGender() const {
	return gender;
}

void Person::setFirstName(const char *firstName) {
	setString(&this->firstName, firstName);
}

void Person::setLastName(const char *lastName) {
	setString(&this->lastName, lastName);
}

void Person::setAge(int age) {
	this->age = age;
}

void Person::setGender(char gender) {
	this->gender = gender;
}
