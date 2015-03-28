#ifndef ALBUM_H
#define ALBUM_H

#include "person.h"

class Album {
private:
	char *name;
	Person *artist;
	int songsCount;

public:
	Album();
	Album(const char *name, const Person &artist, int songsCount);

	~Album();

	char *getName() const;
	Person *getArtist() const;
	int getSongsCount() const;

	void setName(const char *name);
	void setArtist(const Person &artist);
	void setSongsCount(int songsCount);

};

#endif
