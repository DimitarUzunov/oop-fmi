#include <cstring>
#include "song.h"

Song::Song() {
	name = new char[8];
	const char unknown[] = "Unknown";
	strncpy(name, unknown, 8);

	artist = new Person();
	duration = 0;
}

Song::Song(const char *name, const Person &artist, int duration) {
	this->name = NULL;
	this->artist = NULL;
	setName(name);
	setArtist(artist);
	this->duration = duration;
}

Song::~Song() {
	delete[] name;
	name = NULL;
	delete artist;
	artist = NULL;
}

char *Song::getName() const {
	return name;
}

Person *Song::getArtist() const {
	return artist;
}

int Song::getDuration() const {
	return duration;
}

void Song::setName(const char *name) {
	if (this->name) {
		delete[] this->name;
	}

	int nameLen = strlen(name) + 1;
	this->name = new char[nameLen];
	strncpy(this->name, name, nameLen);
}

void Song::setArtist(const Person &artist) {
	if (this->artist) {
		delete this->artist;
	}

	this->artist = new Person(artist);
}

void Song::setDuration(int duration) {
	this->duration = duration;
}
