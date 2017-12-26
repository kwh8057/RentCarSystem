#include "CarInit.h"

list<Car> CarInit() {
	list<Car> * carList = new list<Car>();

	Car * car1 = new Car(1, 5000, "Sonata", "현대", "BLACK");
	Car * car2 = new Car(2, 7000, "K5", "KIA", "GREY");
	Car * car3 = new Car(3, 10000, "그랜저", "현대", "WHITE");

	carList->push_back(*car1);
	carList->push_back(*car2);
	carList->push_back(*car3);

	return *carList;
}