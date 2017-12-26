#include <iostream>
#include "Menu.h"

using namespace std;

void main() {
	int num;

	num = CAR_DISPLAY::Menu();

	if (num == 1) {
		system("cls");

		CAR_DISPLAY::Menu(num);
	}
	else if (!num || num == 2) {
		system("cls");
		return;
	}
}