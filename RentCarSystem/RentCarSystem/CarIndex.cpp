#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include "Menu.h"
#include "Gotoxy.h"
#include "SetColor.h"
#include "CarInit.h"

int CAR_DISPLAY::Menu(int flag)//ȭ�鿡 �������� �͵��� �� Ŭ�������� ����������Դϴ�.
{
	int i, j = 0, x, y, yy, ch, num = 1;

	system("mode con: lines=25 cols=65"); //ȭ���� ũ�⸦ �����մϴ�.
	system("cls");//��ü ȭ���� �����ϰ� ����ϴ�.
	printMenu(num, y, j);//num��ġ�� �޴��� �÷��� �����ְ�, y���� �޾ƿɴϴ�.

	yy = y; //�޴��� ���� �� �𼭸��� y��ǥ���Դϴ�. 
	while (1)
	{
		ch = _getch();//Ű����κ��� �ѹ��ڸ� �Է¹޴´�.
		if (ch == 0xE0)//ȭ��ǥŰ�̸�
		{
			ch = _getch();
			switch (ch)
			{
			case UP: y -= 1; break;
			case DOWN: y += 1; break;
			}
			if (y >= j + yy) y = yy; //�޴��� 7�� �Ʒ��� ������ 1������
			else if (y < yy) y = yy + j - 1;//1�� ���� ������ 7������

			num = y;//��ĭ�� �� �ۼ��Ǿ����� ��ȣ�� 2�� ��������Ѵ�.
			printMenu(num, yy, j); //������ �ٲ������ �÷������� ���ؼ� �ٽ� ���
		}
		else if (ch == ESC) return 0;
		else if (ch == ENTER) return num;
		if (ch < '1' || ch > '7') continue; //���ϴ� Ű�� �ƴϸ� �ٽ� �Է��� �޴´�.
		else break;
	}
	return ch - '0'; //�Է¹޴°� �����̹Ƿ� ���ڷ� �ٲپ �����Ѵ�.
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

		cout << "���� : " << iter->getCarType() << " ���� : " << iter->getColor() << endl;
		iter++;

		if (i == n-1) setColor(WHITE);
	}
	gotoxy(x + 6, y + j);
	printf("ESCŰ�� ������ �����մϴ�.");
	gotoxy(x, y + j + 1);
	printf("%s", EndMenu);
	gotoxy(x, n);
}