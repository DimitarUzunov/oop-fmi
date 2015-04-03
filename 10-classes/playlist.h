#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include "song.h"

class Playlist {
private:
	char *name;
	std::vector<Song> songs;

	void copy(const Playlist &other);
	void destroy();

public:
	Playlist(const char *name = "Unknown");
	Playlist(const Playlist &other);
	Playlist &operator=(const Playlist &other);
	~Playlist();

	const char *getName() const;
	const Song *getSongById(int id) const;
	int getSongsCount() const;

	void setName(const char *name);
	void addSong(Song song);
};

#endif
