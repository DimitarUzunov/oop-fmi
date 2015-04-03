#ifndef PERSON_H
#define PERSON_H

class Person {
private:
	char *firstName;
	char *lastName;
	int age;
	char gender;

	void copy(const Person &other);
	void destroy();
	void setString(char **dest, const char *source);

public:
	Person(const char *firstName = "John", const char *lastName = "Doe",
				int age = 0, char gender = 'm');
	Person(const Person &other);
	Person &operator=(const Person &other);
	~Person();

	const char *getFirstName() const;
	const char *getLastName() const;
	int getAge() const;
	char getGender() const;

	void setFirstName(const char *firstName);
	void setLastName(const char *lastName);
	void setAge(int age);
	void setGender(char gender);
};

#endif
