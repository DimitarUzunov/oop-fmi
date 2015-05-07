#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character {
private:
	int experience;

public:
	Player(const char* name = "unknown", int level = 1, int health = 100,
				int attack = 10, int defense = 10, int mana = 0, int experience = 0);
	~Player();

	int getExperience() const;
};

#endif
