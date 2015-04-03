#include <cstring>
#include "song.h"

void Song::copy(const Song &other) {
	setName(other.name);
	setArtist(other.artist);
	duration = other.duration;
}

void Song::destroy() {
	delete[] name;
	name = NULL;
	delete[] artist;
	artist = NULL;
}

void Song::setString(char **dest, const char *source) {
	delete[] *dest;

	int sourceLen = strlen(source) + 1;
	*dest = new char[sourceLen];
	strncpy(*dest, source, sourceLen);
}

Song::Song(const char *name, const char *artist, int duration) {
	this->name = NULL;
	this->artist = NULL;
	setName(name);
	setArtist(artist);
	this->duration = duration;
}

Song::Song(const Song &other) {
	name = NULL;
	artist = NULL;
	copy(other);
}

Song &Song::operator=(const Song &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Song::~Song() {
	destroy();
}

const char *Song::getName() const {
	return name;
}

const char *Song::getArtist() const {
	return artist;
}

int Song::getDuration() const {
	return duration;
}

void Song::setName(const char *name) {
	setString(&this->name, name);
}

void Song::setArtist(const char *artist) {
	setString(&this->artist, artist);
}

void Song::setDuration(int duration) {
	this->duration = duration;
}
