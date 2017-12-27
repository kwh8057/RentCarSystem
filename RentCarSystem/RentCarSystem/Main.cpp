#include <iostream>
#include "Menu.h"

using namespace std;

void main() {
	int num, carNum;

	num = CAR_DISPLAY::Menu();

	if (num == 1) {
		system("cls");

		carNum = CAR_DISPLAY::Menu(num) - 1;

		system("cls");

		printf("%d", carNum);
	}
	else if (!num || num == 2) {
		system("cls");
		return;
	}
}