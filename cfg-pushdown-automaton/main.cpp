#include "cfg.h"
#include "pda.h"

int main()
{
	// CFG cfg("SABCDEXYZ", "ab", 'S');
	// cfg.addProduction('A', "a");
	// cfg.addProduction('S', "ABCaDE");
	// cfg.addProduction('Y', "Zb");
	// cfg.addProduction('Z', "");
	// cfg.addProduction('X', "ZZ");

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
	//cfg3.addProduction('S', "");
	cfg3.addProduction('S', "AB");
	cfg3.addProduction('A', "AA");
	cfg3.addProduction('B', "BB");
	cfg3.addProduction('A', "a");
	cfg3.addProduction('B', "b");
	std::cout << cfg3 << '\n';
	std::cout << cfg3.contains("ab") << '\n';

	PDA pdaFromCfg(cfg3);
	std::cout << pdaFromCfg.contains("ab") << '\n';
	std::cout << pdaFromCfg << '\n';

	// PDA pda("PQR", "01", "AZ", 'P', 'Z', "R");
	// pda.addTransition('P', '0', 'Z', 'P', "AZ");
	// pda.addTransition('P', '0', 'A', 'P', "AA");
	// pda.addTransition('P', '\0', 'Z', 'Q', "Z");
	// pda.addTransition('P', '\0', 'A', 'Q', "A");
	// pda.addTransition('Q', '1', 'A', 'Q', "");
	// pda.addTransition('Q', '\0', 'Z', 'R', "Z");
	// std::cout << pda << '\n';
	// std::cout << pda.contains("000111") << '\n';

	//CFG cfgFromPda(pda);
	//std::cout << cfgFromPda << '\n';

	return 0;
}
