#ifndef MONSTER_H
#define MONSTER_H

#include "character.h"

class Monster: public Character {
private:

public:
	Monster(const char* name = "unknown", int level = 1, int health = 100,
					int attack = 10, int defense = 10, int mana = 0);
	~Monster();
};

#endif
