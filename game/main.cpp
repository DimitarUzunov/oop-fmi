#include <iostream>
#include "character.h"
#include "player.h"
#include "monster.h"
#include "npc.h"

int main() {
	Character c("gosho", 1, 100, 10, 10, 0);
	Player p("pesho");
	Monster m("joro", 2, 100, 20, 30, 10);
	NPC n("ivancho", 3, 100, 10, 10, 100);

	return 0;
}
