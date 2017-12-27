#include "Car.h"

Car::Car(int carId, int rentalCost, string carType, string manufacturer, string color) {
	this->carId = carId;
	this->rentalCost = rentalCost;
	this->carType = carType;
	this->manufacturer = manufacturer;
	this->color = color;
	this->rentable = true;
}

void Car::checkInsurance() {
	cout << "checkInsurance" << endl;
}

void Car::checkRepair() {
	cout << "checkRepair" << endl;
}