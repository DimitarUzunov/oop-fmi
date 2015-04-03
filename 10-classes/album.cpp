#include <cstring>
#include "album.h"

void Album::copy(const Album &other) {
	setName(other.name);
	setArtist(other.artist);
	songsCount = other.songsCount;
}

void Album::destroy() {
	delete[] name;
	name = NULL;
	delete[] artist;
	artist = NULL;
}

void Album::setString(char **dest, const char *source) {
	delete[] *dest;

	int sourceLen = strlen(source) + 1;
	*dest = new char[sourceLen];
	strncpy(*dest, source, sourceLen);
}

Album::Album(const char *name, const char *artist, int songsCount) {
	this->name = NULL;
	this->artist = NULL;
	setName(name);
	setArtist(artist);
	this->songsCount = songsCount;
}

Album::Album(const Album &other) {
	name = NULL;
	artist = NULL;
	copy(other);
}

Album &Album::operator=(const Album &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Album::~Album() {
	destroy();
}

const char *Album::getName() const {
	return name;
}

const char *Album::getArtist() const {
	return artist;
}

int Album::getSongsCount() const {
	return songsCount;
}

void Album::setName(const char *name) {
	setString(&this->name, name);
}

void Album::setArtist(const char *artist) {
	setString(&this->artist, artist);
}

void Album::setSongsCount(int songsCount) {
	this->songsCount = songsCount;
}
