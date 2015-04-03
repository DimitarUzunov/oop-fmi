#include <cstring>
#include "book.h"

void Book::copy(const Book &other) {
	setName(other.name);
	setAuthor(other.author);
	pagesCount = other.pagesCount;
}

void Book::destroy() {
	delete[] name;
	name = NULL;
	delete[] author;
	author = NULL;
}

void Book::setString(char **dest, const char *source) {
	delete[] *dest;

	int sourceLen = strlen(source) + 1;
	*dest = new char[sourceLen];
	strncpy(*dest, source, sourceLen);
}

Book::Book(const char *name, const char *author, int pagesCount) {
	this->name = NULL;
	this->author = NULL;
	setName(name);
	setAuthor(author);
	this->pagesCount = pagesCount;
}

Book::Book(const Book &other) {
	name = NULL;
	author = NULL;
	copy(other);
}

Book &Book::operator=(const Book &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Book::~Book() {
	destroy();
}

const char *Book::getName() const {
	return name;
}

const char *Book::getAuthor() const {
	return author;
}

int Book::getPagesCount() const {
	return pagesCount;
}

void Book::setName(const char *name) {
	setString(&this->name, name);
}

void Book::setAuthor(const char *author) {
	setString(&this->author, author);
}

void Book::setPagesCount(int pagesCount) {
	this->pagesCount = pagesCount;
}
