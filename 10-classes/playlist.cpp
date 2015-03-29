#include <cstring>
#include "playlist.h"

Playlist::Playlist() {
	name = new char[8];
	const char unknown[] = "Unknown";
	strncpy(name, unknown, 8);

	songsCount = 0;
}

Playlist::Playlist(const char *name) {
	this->name = NULL;
	setName(name);
}

Playlist::~Playlist() {
	delete[] name;
	name = NULL;
}

char *Playlist::getName() const {
	return name;
}

int Playlist::getSongsCount() const {
	return songsCount;
}

// Song *Playlist::getSongById(int id) const {
//
// }

void Playlist::setName(const char *name) {
	if (this->name) {
		delete[] this->name;
	}

	int nameLen = strlen(name) + 1;
	this->name = new char[nameLen];
	strncpy(this->name, name, nameLen);
}

void Playlist::setSongsCount(int songsCount) {
	this->songsCount = songsCount;
}

// void Playlist::addSong(const char &song) {
//
// }
