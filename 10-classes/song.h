#ifndef SONG_H
#define SONG_H

class Song {
private:
	char *name;
	char *artist;
	// TODO: add album field
	int duration; // in seconds

	void copy(const Song &other);
	void destroy();
	void setString(char **dest, const char *source);

public:
	Song(const char *name = "Unknown",
			const char *artist = "Unknown", int duration = 0);
	Song(const Song &other);
	Song &operator=(const Song &other);
	~Song();

	const char *getName() const;
	const char *getArtist() const;
	int getDuration() const;

	void setName(const char *name);
	void setArtist(const char *artist);
	void setDuration(int duration);
};

#endif
