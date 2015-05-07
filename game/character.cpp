#include <iostream>
#include <cstring>
#include "character.h"

void Character::copy(const Character& other) {
	setName(other.name);
	level = other.level;
	health = other.health;
	attack = other.attack;
	defense = other.defense;
	mana = other.mana;
}

void Character::destroy() {
	delete[] name;
}

void Character::setName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Character::Character(const char* name, int level, int health,
										int attack, int defense, int mana)
										: name(NULL), level(level), health(health),
										attack(attack), defense(defense), mana(mana) {
											setName(name);
											std::cout << "Character()\n";
}

Character::Character(const Character& other): name(NULL) {
	copy(other);
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Character::~Character() {
	destroy();
	std::cout << "~Character()\n";
}

const char* Character::getName() const {
	return name;
}

int Character::getLevel() const {
	return level;
}

int Character::getHealth() const {
	return health;
}

int Character::getAttack() const {
	return attack;
}

int Character::getDefense() const {
	return defense;
}

int Character::getMana() const {
	return mana;
}
