#ifndef TRAIN_H
#define TRAIN_H

class Train {
private:
	int carsCount;
	int seatsInCar;
	bool isWrecked;

public:
	Train(int carsCount = 1, int seatsInCar = 10, bool isWrecked = false);

	int getCarsCount() const;
	int getSeatsInCar() const;
	int getAllSeats() const;
	bool getIsWrecked() const;

	void setCarsCount(int carsCount);
	void setSeatsInCar(int seatsInCar);
	void toggleIsWrecked();
};

#endif
