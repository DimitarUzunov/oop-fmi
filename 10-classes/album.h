#ifndef ALBUM_H
#define ALBUM_H

class Album {
private:
	char *name;
	char *artist;
	int songsCount;

	void copy(const Album &other);
	void destroy();
	void setString(char **dest, const char *source);

public:
	Album(const char *name = "Unknown",
				const char *artist = "Unknown", int songsCount = 0);
	Album(const Album &other);
	Album &operator=(const Album &other);
	~Album();

	const char *getName() const;
	const char *getArtist() const;
	int getSongsCount() const;

	void setName(const char *name);
	void setArtist(const char *artist);
	void setSongsCount(int songsCount);
};

#endif
