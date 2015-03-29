#include "train.h"

Train::Train(int carsCount, int seatsInCar, bool isWrecked) {
	this->carsCount = carsCount;
	this->seatsInCar = seatsInCar;
	this->isWrecked = isWrecked;
}

int Train::getCarsCount() const {
	return carsCount;
}

int Train::getSeatsInCar() const {
	return seatsInCar;
}

int Train::getAllSeats() const {
	return carsCount * seatsInCar;
}

bool Train::getIsWrecked() const {
	return isWrecked;
}

void Train::setCarsCount(int carsCount) {
	this->carsCount = carsCount;
}

void Train::setSeatsInCar(int seatsInCar) {
	this->seatsInCar = seatsInCar;
}

void Train::toggleIsWrecked() {
	if (isWrecked) {
		isWrecked = false;
	} else {
		isWrecked = true;
	}
}
