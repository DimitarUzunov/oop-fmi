#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
	char* name;
	int level;
	int health;
	int attack;
	int defense;
	int mana;

	void copy(const Character& other);
	void destroy();
	void setName(const char* name);

public:
	Character(const char* name = "unknown", int level = 1, int health = 100,
						int attack = 0, int defense = 0, int mana = 0);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	const char* getName() const;
	int getLevel() const;
	int getHealth() const;
	int getAttack() const;
	int getDefense() const;
	int getMana() const;
};

#endif
