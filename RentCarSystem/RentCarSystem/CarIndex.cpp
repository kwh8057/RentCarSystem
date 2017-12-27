#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include "Menu.h"
#include "Gotoxy.h"
#include "SetColor.h"
#include "CarInit.h"

int CAR_DISPLAY::Menu(int flag)//화면에 보여지는 것들은 이 클래스에서 만들어질것입니다.
{
	int i, j = 0, x, y, yy, ch, num = 1;

	system("mode con: lines=25 cols=65"); //화면의 크기를 조절합니다.
	system("cls");//전체 화면을 깨끗하게 지웁니다.
	printMenu(num, y, j);//num위치의 메뉴를 컬러로 보여주고, y값을 받아옵니다.

	yy = y; //메뉴의 왼쪽 위 모서리의 y좌표값입니다. 
	while (1)
	{
		ch = _getch();//키보드로부터 한문자를 입력받는다.
		if (ch == 0xE0)//화살표키이면
		{
			ch = _getch();
			switch (ch)
			{
			case UP: y -= 1; break;
			case DOWN: y += 1; break;
			}
			if (y >= j + yy) y = yy; //메뉴의 7번 아래로 누르면 1번으로
			else if (y < yy) y = yy + j - 1;//1번 위로 누르면 7번으로

			num = y;//한칸씩 띄어서 작성되었으니 번호는 2로 나누어야한다.
			printMenu(num, yy, j); //선택이 바뀌었으니 컬러변경을 위해서 다시 출력
		}
		else if (ch == ESC) return 0;
		else if (ch == ENTER) return num;
		if (ch < '1' || ch > '7') continue; //원하는 키가 아니면 다시 입력을 받는다.
		else break;
	}
	return ch - '0'; //입력받는게 문자이므로 숫자로 바꾸어서 리턴한다.
}

void CAR_DISPLAY::printMenu(int n, int &y, int &j)
{
	int i, x;
	j = 0;
	const char MainMenu[] = { "=========== C A R  I N D E X ===========\n" };
	const char EndMenu[] = { "======================================== " };

	list<Car> * carList = new list<Car>();
	*carList = CarInit();

	list<Car>::iterator iter;

	for (iter = carList->begin(); iter != carList->end(); ++iter) {
		if (iter->getRentable() == true) {
			j++;
		}
	}

	gotoxy(13, 0);
	printf("%s", MainMenu);

	iter = carList->begin();
	x = 13; y = 1;
	for (i = 0; i < j; i++) {
		gotoxy(x + 6, y + i);
		if (i == n-1) setColor(GREEN);

		cout << "차종 : " << iter->getCarType() << " 색상 : " << iter->getColor() << endl;
		iter++;

		if (i == n-1) setColor(WHITE);
	}
	gotoxy(x + 6, y + j);
	printf("ESC키를 누르면 종료합니다.");
	gotoxy(x, y + j + 1);
	printf("%s", EndMenu);
	gotoxy(x, n);
}