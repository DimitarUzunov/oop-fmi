#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"

class Playlist {
private:
	char *name;
	int songsCount;
	// Song *songs; // vector of songs

public:
	Playlist();
	Playlist(const char *name);

	~Playlist();

	char *getName() const;
	int getSongsCount() const;
	Song *getSongById(int id) const;

	void setName(const char *name);
	void setSongsCount(int songsCount);
	void addSong(const char &song);

};

#endif
