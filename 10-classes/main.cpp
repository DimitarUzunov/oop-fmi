#include <iostream>

#include "guitar.h"
#include "person.h"
#include "song.h"
#include "album.h"
#include "dog.h"
#include "train.h"
#include "book.h"
#include "circle.h"

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
	Person author("Robin", "Sharma", 49, 'm');
	Book book("The leader who had no title", author, 300);

	std::cout << '\'' << book.getName() << "' by " << book.getAuthor()->getFirstName() << ' ' << book.getAuthor()->getLastName() << '\n';
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
	// testDog();
	// testTrain();
	// testBook();
	testCircle();

	return 0;
}
