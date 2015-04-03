#include <cstring>
#include "playlist.h"

void Playlist::copy(const Playlist &other) {
	setName(other.name);
	songs = other.songs;
}

void Playlist::destroy() {
	delete[] name;
	name = NULL;
}

Playlist::Playlist(const char *name) {
	this->name = NULL;
	setName(name);
}

Playlist::Playlist(const Playlist &other) {
	name = NULL;
	copy(other);
}

Playlist &Playlist::operator=(const Playlist &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Playlist::~Playlist() {
	destroy();
}

const char *Playlist::getName() const {
	return name;
}

const Song *Playlist::getSongById(int id) const {
	if (getSongsCount() <= 0 || id < 0 || id >= getSongsCount()) {
		return NULL;
	}
	return &songs[id];
}

int Playlist::getSongsCount() const {
	return songs.size();
}

void Playlist::setName(const char *name) {
	delete[] this->name;

	int nameLen = strlen(name) + 1;
	this->name = new char[nameLen];
	strncpy(this->name, name, nameLen);
}

void Playlist::addSong(Song song) {
	songs.push_back(song);
}
