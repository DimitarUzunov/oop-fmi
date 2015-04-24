#ifndef EVENT_LOG_H
#define EVENT_LOG_H

#include <iostream>

const int MAX = 30;

class EventLog {
private:
	char name[MAX];
	char **events;
	int size;
	int capacity;

	void copy(const EventLog &other);
	void destroy();
	void resize();

public:
	EventLog(const char *name = "Events", int capacity = 4);
	EventLog(const char *name, const char **events, int count);
	EventLog(const EventLog &other);
	EventLog &operator=(const EventLog &other);
	~EventLog();

	const char *getName() const;
	char **getEvents() const;
	int getSize() const;

	void setName(const char *name);

	void addEvent(const char *event);
	void clear();
};

std::ostream &operator<<(std::ostream &os, const EventLog &eventLog);

#endif
