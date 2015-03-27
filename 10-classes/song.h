#ifndef SONG_H
#define SONG_H

#include "person.h"

class Song {
private:
	char *name;
	Person *artist;
	// TODO: add album field
	int duration; // in seconds

public:
	Song();
	Song(const char *name, const Person &artist, int duration);

	~Song();

	char *getName() const;
	Person *getArtist() const;
	int getDuration() const;

	void setName(const char *name);
	void setArtist(const Person &artist);
	void setDuration(int duration);
};

#endif
