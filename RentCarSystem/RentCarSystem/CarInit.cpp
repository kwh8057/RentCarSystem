#include "CarInit.h"

list<Car> CarInit() {
	list<Car> * carList = new list<Car>();

	Car * car1 = new Car(1, 5000, "Sonata", "HYUNDAI", "BLACK");
	Car * car2 = new Car(2, 7000, "K5", "KIA", "GRAY");
	Car * car3 = new Car(3, 10000, "Grandeur", "HYUNDAI", "WHITE");
	Car * car4 = new Car(4, 3000, "Avante", "Hyundai", "BLACK");

	carList->push_back(*car1);
	carList->push_back(*car2);
	carList->push_back(*car3);
	carList->push_back(*car4);

	return *carList;
}