#include "Menu.h"
#include "Gotoxy.h"
#include "SetColor.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

int CAR_DISPLAY::Menu(int flag)//화면에 보여지는 것들은 이 클래스에서 만들어질것입니다.
{
	int i, x, y, yy, ch, num = 1;

	system("mode con: lines=25 cols=65"); //화면의 크기를 조절합니다.
	system("cls");//전체 화면을 깨끗하게 지웁니다.
	printMenu(num, y, flag);//num위치의 메뉴를 컬러로 보여주고, y값을 받아옵니다.

	yy = y; //메뉴의 왼쪽 위 모서리의 y좌표값입니다. 
	y = yy + 2;//1번 메뉴위치의 y값
	while (1)
	{
		ch = _getch();//키보드로부터 한문자를 입력받는다.
		if (ch == 0xE0)//화살표키이면
		{
			ch = _getch();
			switch (ch)
			{
			case UP: y -= 2; break;
			case DOWN: y += 2; break;
			}
			if (y > 4 + yy) y = yy + 2; //메뉴의 7번 아래로 누르면 1번으로
			else if (y < yy + 2) y = yy + 4;//1번 위로 누르면 7번으로

			num = (y - yy) / 2;//한칸씩 띄어서 작성되었으니 번호는 2로 나누어야한다.
			printMenu(num, yy, flag); //선택이 바뀌었으니 컬러변경을 위해서 다시 출력
		}
		else if (ch == ESC || ch == '7') return 0;
		else if (ch == ENTER) return num;
		if (ch < '1' || ch > '7') continue; //원하는 키가 아니면 다시 입력을 받는다.
		else break;
	}
	return ch - '0'; //입력받는게 문자이므로 숫자로 바꾸어서 리턴한다.
}

void CAR_DISPLAY::printMenu(int n, int &y, int flag)
{
	int i, x;
	const char *MainMenu[] = { "=========== C A R  I N D E X ===========",
		"|                                      |",
		"|            1. 렌      트             |",
		"|                                      |",
		"|            2. 종      료             |",
		"|                                      |",
		"========================================" };

	x = 33 - lstrlen(MainMenu[0]) / 2;
	y = 13 - sizeof(MainMenu) / sizeof(MainMenu[0]) / 2 - 1;
	for (i = 0; i < sizeof(MainMenu) / sizeof(MainMenu[0]); i++)
	{
		gotoxy(x, y + i);
		if (i == n * 2) setColor(GREEN);//선택된 번호의 메뉴를 컬러로 출력
		printf("%s", MainMenu[i]);
		if (i == n * 2) setColor(WHITE); //컬러를 원상태로 복구
	}
	gotoxy(x, y + n * 2);//커서를 선택된 번호 위치로
}