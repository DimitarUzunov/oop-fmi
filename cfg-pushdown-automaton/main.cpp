#include <iostream>
#include "cfg.h"

int main()
{
	CFG cfg("SABCDEYZ", "ab", 'S');
	cfg.addProduction('A', "");
	cfg.addProduction('S', "ABCaDE");
	cfg.addProduction('Y', "ZZ");
	cfg.addProduction('Z', "");

	std::cout << cfg << "\n\nRemove long productions\n";
	cfg.removeLongProductions();
	std::cout << cfg << "\n\n";

	std::cout << "Remove epsilon productions\n";
	cfg.removeEpsProductions();
	std::cout << cfg << "\n\n";

	std::cout << "Remove terminals\n";
	cfg.removeTerminals();
	std::cout << cfg << "\n\n";

	std::cout << cfg.isInCNF() << '\n';

	return 0;
}
