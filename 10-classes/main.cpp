#include <iostream>

#include "guitar.h"
#include "person.h"
#include "song.h"
#include "album.h"
#include "playlist.h"
#include "polygon.h"
#include "dog.h"
#include "train.h"
#include "book.h"
#include "circle.h"

void testGuitar() {
	Guitar acoustic;
	Guitar electric = acoustic;

	electric.setType("Electric");
	electric.setFrets(22);

	std::cout << electric.getType() << '\n';
	std::cout << acoustic.getType() << '\n';

	electric = acoustic;

	std::cout << electric.getType() << '\n';
}

void testPerson() {
	Person maria;

	maria = Person("Maria", "Penkova", 19, 'f');

	std::cout << maria.getFirstName() << '\n';
	std::cout << maria.getLastName() << '\n';
}

void testSong() {
	Song unknown;
	Song song("Bent to fly", "Slash", 297);

	unknown = song;
	unknown.setName("Too far gone");
	unknown.setDuration(247);

	std::cout << song.getName() << '\n';
	std::cout << song.getArtist() << '\n';
	std::cout << unknown.getName() << '\n';
	std::cout << unknown.getArtist() << '\n';
}

void testAlbum() {
	Album album("World on fire", "Slash", 17);

	std::cout << album.getName() << '\n';
	std::cout << album.getArtist() << '\n';
	std::cout << album.getSongsCount() << '\n';

	Album apocalyptic = album;
	apocalyptic.setName("Apocalyptic love");
	apocalyptic.setSongsCount(15);

	std::cout << album.getName() << '\n';
	std::cout << apocalyptic.getName() << '\n';
	std::cout << apocalyptic.getArtist() << '\n';
	std::cout << apocalyptic.getSongsCount() << '\n';
}

void testPlaylist() {
	Playlist playlist;
	playlist.addSong(Song());
	Playlist rockNRoll = playlist;

	rockNRoll.setName("Rock 'n' roll");
	rockNRoll.addSong(Song("Bent to fly", "Slash", 297));
	rockNRoll.addSong(Song("Too far gone", "Slash", 247));

	std::cout << playlist.getName() << '\n';
	std::cout << rockNRoll.getName() << '\n';
	for (int i = 0; i < rockNRoll.getSongsCount(); i++) {
		std::cout << rockNRoll.getSongById(i)->getName() << '\n';
	}

	Playlist metal;
	metal = rockNRoll;
	metal.setName("Metal");
	metal.addSong(Song("Nothing to say", "Slash", 326));

	for (int i = 0; i < metal.getSongsCount(); i++) {
		std::cout << metal.getSongById(i)->getName() << '\n';
	}
}

void testPolygon() {
	Polygon triangle;
	triangle.setSideLength(10);

	std::cout << "Perimeter: " << triangle.getPerimeter() << '\n';
	std::cout << "Area: " << triangle.getArea() << '\n';
}

void testDog() {
	Dog dog("Rex", "Normal", 1);
	dog.bark();
}

void testTrain() {
	Train train(13, 13);

	std::cout << "The train has " << train.getAllSeats() << " seats.\n";

	train.toggleIsWrecked();
	std::cout << "The train is ";
	if (train.getIsWrecked()) {
		std::cout << "wrecked!\n";
	} else {
		std::cout << "not wrecked.\n";
	}
}

void testBook() {
	Book book("The leader who had no title", "Robin Sharma", 203);

	std::cout << '\'' << book.getName() << "' by " << book.getAuthor() << '\n';
}

void testCircle() {
	Circle circle;
	circle.setRadius(13);

	std::cout << "Perimeter: " << circle.getPerimeter() << '\n';
	std::cout << "Area: " << circle.getArea() << '\n';
}

int main() {
	// testGuitar();
	// testPerson();
	// testSong();
	// testAlbum();
	// testPlaylist();
	// testPolygon();
	// testDog();
	// testTrain();
	// testBook();
	testCircle();

	return 0;
}
