#include "cfg.h"

int main()
{
	CFG cfg("SABCDEXYZ", "ab", 'S');
	// cfg.addProduction('A', "a");
	cfg.addProduction('S', "ABCaDE");
	cfg.addProduction('Y', "Zb");
	cfg.addProduction('Z', "");
	cfg.addProduction('X', "ZZ");

	// CFG cfg2("QRTW", "abcqt", 'Q');
	// cfg2.addProduction('Q', "ab");
	// cfg2.addProduction('Q', "RT");
	// cfg2.addProduction('R', "ct");
	// cfg2.addProduction('T', "Wq");
	// cfg2.addProduction('W', "t");

	// std::cout << iterate(cfg2) << '\n';

	// std::cout << cfg << "\n\nRemove long productions\n";
	// cfg.removeLongProductions();
	// std::cout << cfg << "\n\n";
	//
	// std::cout << "Remove epsilon productions\n";
	// cfg.removeEpsProductions();
	// std::cout << cfg << "\n\n";
	//
	// std::cout << "Remove terminals\n";
	// cfg.removeTerminals();
	// std::cout << cfg << "\n\n";
	//
	// std::cout << cfg.isInCNF() << '\n';

	CFG cfg3("SAB", "ab", 'S');
	cfg3.addProduction('S', "");
	cfg3.addProduction('S', "AB");
	cfg3.addProduction('A', "AA");
	cfg3.addProduction('B', "BB");
	cfg3.addProduction('A', "a");
	cfg3.addProduction('B', "b");
	std::cout << cfg3.contains("ab") << '\n';

	return 0;
}
