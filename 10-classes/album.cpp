#include <cstring>
#include "album.h"

Album::Album() {
	name = new char[8];
	const char unknown[] = "Unknown";
	strncpy(name, unknown, 8);

	artist = new Person();
	songsCount = 0;
}

Album::Album(const char *name, const Person &artist, int songsCount) {
	this->name = NULL;
	this->artist = NULL;
	setName(name);
	setArtist(artist);
	this->songsCount = songsCount;
}

Album::~Album() {
	delete[] name;
	name = NULL;
	delete artist;
	artist = NULL;
}

char *Album::getName() const {
	return name;
}

Person *Album::getArtist() const {
	return artist;
}

int Album::getSongsCount() const {
	return songsCount;
}

void Album::setName(const char *name) {
	if (this->name) {
		delete[] this->name;
	}

	int nameLen = strlen(name) + 1;
	this->name = new char[nameLen];
	strncpy(this->name, name, nameLen);
}

void Album::setArtist(const Person &artist) {
	if (this->artist) {
		delete this->artist;
	}

	this->artist = new Person(artist);
}

void Album::setSongsCount(int songsCount) {
	this->songsCount = songsCount;
}
