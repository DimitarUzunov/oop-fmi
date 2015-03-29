#ifndef DOG_H
#define DOG_H

class Dog {
private:
	char *name;
	char *breed;
	int age;

	void setStringField(char **dest, const char *source);

public:
	Dog(const char *name = "Rex", const char *breed = "Normal", int age = 1);

	~Dog();

	char *getName() const;
	char *getBreed() const;
	int getAge() const;
	void bark() const;

	void setName(const char *name);
	void setBreed(const char *breed);
	void setAge(int age);

};

#endif
