#include <iostream>

#include "guitar.h"
#include "person.h"
#include "song.h"
#include "album.h"

void testGuitar() {
	char electric[] = "Electric";
	Guitar guitar(electric, 6, 22);

	std::cout << guitar.getType() << '\n';
	guitar.setType("Acoustic");
	std::cout << guitar.getType() << '\n';
	std::cout << guitar.getStrings() << '\n';
	std::cout << guitar.getFrets() << '\n';
}

void testPerson() {
	Person person;
	std::cout << person.getFirstName() << '\n';

	Person maria("Maria", "Penkova", 19, 'f');
	std::cout << maria.getLastName() << '\n';
}

void testSong() {
	Person artist("Slash", "Hudson", 49, 'm');
	Song song("Bent to fly", artist, 297);

	std::cout << song.getName() << '\n';
	std::cout << song.getArtist()->getFirstName() << '\n';
}

void testAlbum() {
	Person artist("Slash", "Hudson", 49, 'm');
	Album album("World on fire", artist, 17);

	std::cout << album.getName() << '\n';
	std::cout << album.getArtist()->getFirstName() << '\n';
	std::cout << album.getSongsCount() << '\n';

	album.setName("Apocalyptic love");
	album.setSongsCount(15);

	std::cout << album.getName() << '\n';
	std::cout << album.getArtist()->getFirstName() << '\n';
	std::cout << album.getSongsCount() << '\n';
}

int main() {
	// testGuitar();
	// testPerson();
	// testSong();
	testAlbum();

	return 0;
}
