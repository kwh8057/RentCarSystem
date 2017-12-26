#include "CarInit.h"

list<Car> CarInit() {
	list<Car> * carList = new list<Car>();

	Car * car1 = new Car(1, 5000, "Sonata", "Çö´ë", "BLACK");
	Car * car2 = new Car(2, 7000, "K5", "KIA", "GREY");
	Car * car3 = new Car(3, 10000, "ą×ˇŁŔú", "Çö´ë", "WHITE");
	Car * car4 = new Car(4, 3000, "Avante", "Hyundai", "BLACK");

	carList->push_back(*car1);
	carList->push_back(*car2);
	carList->push_back(*car3);
	carList->push_back(*car4);

	return *carList;
}
