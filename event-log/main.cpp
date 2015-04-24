#include <iostream>
#include "event_log.h"

int main() {
	const char *events[] = {"Star Wars", "GoT", "Furious 7"};
	EventLog eventLog("Movies", events, 3);

	std::cout << eventLog;

	eventLog.clear();
	eventLog.setName("Concerts");
	eventLog.addEvent("Slash");

	std::cout << eventLog;

	EventLog concerts;
	concerts = eventLog;
	eventLog.clear();
	concerts.addEvent("Guns N' Roses");

	std::cout << concerts;

	return 0;
}
