#ifndef PERSON_H
#define PERSON_H

class Person {
private:
	char *firstName;
	char *lastName;
	int age;
	char gender;

	void setName(char **dest, const char *source);

public:
	Person();
	Person(const char *firstName, const char *lastName, int age, char gender);

	~Person();

	char *getFirstName() const;
	char *getLastName() const;
	int getAge() const;
	char getGender() const;

	void setFirstName(const char *firstName);
	void setLastName(const char *lastName);
	void setAge(int age);
	void setGender(char gender);
};

#endif
