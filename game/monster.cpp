#include <iostream>
#include "monster.h"

Monster::Monster(const char* name, int level, int health,
								int attack, int defense, int mana)
								: Character(name, level, health, attack, defense, mana) {
									std::cout << "Monster()\n";
}

Monster::~Monster() {
	std::cout << "~Monster()\n";
}
