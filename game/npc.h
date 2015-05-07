#ifndef NPC_H
#define NPC_H

#include "character.h"

class NPC: public Character {
private:

public:
	NPC(const char *name = "unknown", int level = 1, int health = 100,
					int attack = 10, int defense = 10, int mana = 0);
	~NPC();
};

#endif
