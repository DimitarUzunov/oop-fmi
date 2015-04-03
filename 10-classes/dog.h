#ifndef DOG_H
#define DOG_H

class Dog {
private:
	char *name;
	char *breed;
	int age;

	void copy(const Dog &other);
	void destroy();
	void setString(char **dest, const char *source);

public:
	Dog(const char *name = "Rex", const char *breed = "Normal", int age = 0);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	const char *getName() const;
	const char *getBreed() const;
	int getAge() const;
	void bark() const;

	void setName(const char *name);
	void setBreed(const char *breed);
	void setAge(int age);
};

#endif
