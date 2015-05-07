#include <iostream>
#include "player.h"

Player::Player(const char* name, int level, int health, int attack,
							int defense, int mana, int experience)
							: Character(name, level, health, attack, defense, mana),
							experience(experience) {
								std::cout << "Player()\n";
}

Player::~Player() {
	std::cout << "~Player()\n";
}

int Player::getExperience() const {
	return experience;
}
