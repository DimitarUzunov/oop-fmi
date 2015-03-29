#ifndef BOOK_H
#define BOOK_H

#include "person.h"

class Book {
private:
	char *name;
	Person *author;
	int pagesCount;

public:
	Book();
	Book(const char *name, const Person &author, int pagesCount);

	~Book();

	char *getName() const;
	Person *getAuthor() const;
	int getPagesCount() const;

	void setName(const char *name);
	void setAuthor(const Person &author);
	void setPagesCount(int pagesCount);

};

#endif
