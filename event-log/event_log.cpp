#include <iostream>
#include <cstring>
#include "event_log.h"

void EventLog::copy(const EventLog &other) {
	setName(other.name);
	size = 0;
	capacity = other.capacity;
	events = new char*[capacity];
	for (int i = 0; i < other.size; i++) {
		addEvent(other.events[i]);
	}
}

void EventLog::destroy() {
	clear();
	delete[] events;
	events = NULL;
}

void EventLog::resize() {
	capacity *= 2;
	char **newEvents = new char*[capacity];
	for (int i = 0; i < size; i++) {
		newEvents[i] = events[i];
	}
	delete[] events;
	events = newEvents;
}

EventLog::EventLog(const char *name, int capacity) {
	setName(name);
	events = new char*[capacity];
	size = 0;
	this->capacity = capacity;
}

EventLog::EventLog(const char *name, const char **events, int count) {
	setName(name);
	size = 0;
	capacity = count;
	this->events = new char*[capacity];
	for (int i = 0; i < capacity; i++) {
		addEvent(events[i]);
	}
}

EventLog::EventLog(const EventLog &other) {
	copy(other);
}

EventLog &EventLog::operator=(const EventLog &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

EventLog::~EventLog() {
	destroy();
}

const char *EventLog::getName() const {
	return name;
}

char **EventLog::getEvents() const {
	return events;
}

int EventLog::getSize() const {
	return size;
}

void EventLog::setName(const char *name) {
	strncpy(this->name, name, MAX);
	this->name[MAX - 1] = '\0';
}

void EventLog::addEvent(const char *event) {
	if (size == capacity) {
		resize();
	}

	events[size] = new char[strlen(event) + 1];
	strcpy(events[size++], event);
}

void EventLog::clear() {
	for (int i = 0; i < size; i++) {
		delete[] events[i];
	}
	size = 0;
}

std::ostream &operator<<(std::ostream &os, const EventLog &eventLog) {
	if (eventLog.getSize() == 0) {
		os << "The event log with name '"
			<< eventLog.getName() << "' has no events.\n";
		return os;
	}

	os << "The event log with name '" << eventLog.getName()
		<< "' has the following events:\n";
	for (int i = 0; i < eventLog.getSize(); i++) {
		os << eventLog.getEvents()[i] << '\n';
	}

	return os;
}
