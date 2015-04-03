#ifndef BOOK_H
#define BOOK_H

class Book {
private:
	char *name;
	char *author;
	int pagesCount;

	void copy(const Book &other);
	void destroy();
	void setString(char **dest, const char *source);

public:
	Book(const char *name = "Unknown",
			const char *author = "Unknown", int pagesCount = 0);
	Book(const Book &other);
	Book &operator=(const Book &other);
	~Book();

	const char *getName() const;
	const char *getAuthor() const;
	int getPagesCount() const;

	void setName(const char *name);
	void setAuthor(const char *author);
	void setPagesCount(int pagesCount);
};

#endif
