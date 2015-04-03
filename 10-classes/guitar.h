#ifndef GUITAR_H
#define GUITAR_H

class Guitar {
private:
	char *type;
	int strings;
	int frets;

	void copy(const Guitar &other);
	void destroy();

public:
	Guitar(const char *type = "Acoustic", int strings = 6, int frets = 19);
	Guitar(const Guitar &other);
	Guitar &operator=(const Guitar &other);
	~Guitar();

	const char *getType() const;
	int getStrings() const;
	int getFrets() const;

	void setType(const char *type);
	void setStrings(int strings);
	void setFrets(int frets);
};

#endif
