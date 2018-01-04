#include <iostream>
#include "Menu.h"
#include "CarInfo.h"
#include "CarInit.h"

using namespace std;

int main() {
	int num;
	list<Car>::iterator iter;
	list<Car> * carList = new list<Car>();
	*carList = CarInit();

	num = CAR_DISPLAY::Menu();

	if (num == 1) {
		while (1) {
			system("cls");

			iter = CAR_DISPLAY::Menu(num, *carList);

			system("cls");
	
			PrintCarInfo(iter, *carList);
		}
	}
	else if (!num || num == 2) {
		system("cls");
		exit(-1);
	}

	return 0;
}