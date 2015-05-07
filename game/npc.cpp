#include <iostream>
#include "npc.h"

NPC::NPC(const char *name, int level, int health,
								int attack, int defense, int mana)
								: Character(name, level, health, attack, defense, mana) {
									std::cout << "NPC()\n";
}

NPC::~NPC() {
	std::cout << "~NPC()\n";
}
