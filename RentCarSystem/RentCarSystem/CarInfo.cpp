#include <string>
#include <conio.h>
#include "CarInit.h"
#include "CarInfo.h"
#include "Car.h"
#include "Gotoxy.h"

void PrintCarInfo(list<Car>::iterator it, list<Car> & carList) {
	const char MainMenu[] = { "============ C A R  I N F O ============\n" };
	const char EndMenu[] = { "======================================== " };
	char ch;

	list<Car>::iterator iter = carList.begin();
	
	while (iter->getCarId() != it->getCarId()) {
		iter++;
	}

	gotoxy(13, 0);
	printf("%s", MainMenu);

	for (int i = 0; i < 6; i++) {
		gotoxy(24, i + 1);
		switch (i) {
		case 0: cout << "차량ID : " << iter->getCarId(); break;
		case 1: cout << "차종 : " << iter->getCarType(); break;
		case 2: cout << "제조회사 : " << iter->getManufacturer(); break;
		case 3: cout << "렌트비 : " << iter->getRentalCost(); break;
		case 4: cout << "색상 : " << iter->getColor(); break;
		case 5: 
			cout << "렌트 가능 여부 : "; 
			if (iter->getRentable() == true) cout << "가능";
			else cout << "불가능";
			break;
		}
	}
	gotoxy(13, 7);
	printf("%s\n", EndMenu);

	if (iter->getRentable() == true) {
		gotoxy(18, 10);
		cout << "렌트 신청하시겠습니까? (Y / N) : ";
		ch = _getch();

		if (ch == 'Y' || ch == 'y') {
			iter->setRentable(false);
		}
		else if (ch == 'N' || ch == 'n') {
			return;
		}
		else {
			system("cls");
			gotoxy(19, 10);
			cout << "올바른 키를 눌러주세요.";
			gotoxy(13, 11);
			system("pause");
			return;
		}
	}
	else {
		gotoxy(18, 10);
		cout << "반납하시겠습니까? (Y / N) : ";
		ch = _getch();

		if (ch == 'Y' || ch == 'y') {
			iter->setRentable(true);
		}
		else if (ch == 'N' || ch == 'n') {
			return;
		}
		else {
			system("cls");
			gotoxy(19, 10);
			cout << "올바른 키를 눌러주세요.";
			gotoxy(13, 11);
			system("pause");
			return;
		}
	}
}