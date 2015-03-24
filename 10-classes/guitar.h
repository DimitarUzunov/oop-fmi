#ifndef GUITAR_H
#define GUITAR_H

class Guitar {
private:
	char *type;
	int strings;
	int frets;

public:
	Guitar();
	Guitar(const char *type, int strings, int frets);

	char *getType() const;
	int getStrings() const;
	int getFrets() const;

	void setType(const char *type);
	void setStrings(int strings);
	void setFrets(int frets);

	~Guitar();
};

#endif
