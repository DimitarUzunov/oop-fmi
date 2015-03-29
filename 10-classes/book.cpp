#include <cstring>
#include "book.h"

Book::Book() {
	name = new char[8];
	const char unknown[] = "Unknown";
	strncpy(name, unknown, 8);

	author = new Person();
	pagesCount = 0;
}

Book::Book(const char *name, const Person &author, int pagesCount) {
	this->name = NULL;
	this->author = NULL;
	setName(name);
	setAuthor(author);
	this->pagesCount = pagesCount;
}

Book::~Book() {
	delete[] name;
	name = NULL;
	delete author;
	author = NULL;
}

char *Book::getName() const {
	return name;
}

Person *Book::getAuthor() const {
	return author;
}

int Book::getPagesCount() const {
	return pagesCount;
}

void Book::setName(const char *name) {
	if (this->name) {
		delete[] this->name;
	}

	int nameLen = strlen(name) + 1;
	this->name = new char[nameLen];
	strncpy(this->name, name, nameLen);
}

void Book::setAuthor(const Person &author) {
	if (this->author) {
		delete this->author;
	}

	this->author = new Person(author);
}

void Book::setPagesCount(int pagesCount) {
	this->pagesCount = pagesCount;
}
