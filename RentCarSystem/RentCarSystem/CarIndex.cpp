#include "Menu.h"
#include "Gotoxy.h"
#include "SetColor.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

int CAR_DISPLAY::Menu(int flag)//ȭ�鿡 �������� �͵��� �� Ŭ�������� ����������Դϴ�.
{
	int i, x, y, yy, ch, num = 1;

	system("mode con: lines=25 cols=65"); //ȭ���� ũ�⸦ �����մϴ�.
	system("cls");//��ü ȭ���� �����ϰ� ����ϴ�.
	printMenu(num, y, flag);//num��ġ�� �޴��� �÷��� �����ְ�, y���� �޾ƿɴϴ�.

	yy = y; //�޴��� ���� �� �𼭸��� y��ǥ���Դϴ�. 
	y = yy + 2;//1�� �޴���ġ�� y��
	while (1)
	{
		ch = _getch();//Ű����κ��� �ѹ��ڸ� �Է¹޴´�.
		if (ch == 0xE0)//ȭ��ǥŰ�̸�
		{
			ch = _getch();
			switch (ch)
			{
			case UP: y -= 2; break;
			case DOWN: y += 2; break;
			}
			if (y > 4 + yy) y = yy + 2; //�޴��� 7�� �Ʒ��� ������ 1������
			else if (y < yy + 2) y = yy + 4;//1�� ���� ������ 7������

			num = (y - yy) / 2;//��ĭ�� �� �ۼ��Ǿ����� ��ȣ�� 2�� ��������Ѵ�.
			printMenu(num, yy, flag); //������ �ٲ������ �÷������� ���ؼ� �ٽ� ���
		}
		else if (ch == ESC || ch == '7') return 0;
		else if (ch == ENTER) return num;
		if (ch < '1' || ch > '7') continue; //���ϴ� Ű�� �ƴϸ� �ٽ� �Է��� �޴´�.
		else break;
	}
	return ch - '0'; //�Է¹޴°� �����̹Ƿ� ���ڷ� �ٲپ �����Ѵ�.
}

void CAR_DISPLAY::printMenu(int n, int &y, int flag)
{
	int i, x;
	const char *MainMenu[] = { "=========== C A R  I N D E X ===========",
		"|                                      |",
		"|            1. ��      Ʈ             |",
		"|                                      |",
		"|            2. ��      ��             |",
		"|                                      |",
		"========================================" };

	x = 33 - lstrlen(MainMenu[0]) / 2;
	y = 13 - sizeof(MainMenu) / sizeof(MainMenu[0]) / 2 - 1;
	for (i = 0; i < sizeof(MainMenu) / sizeof(MainMenu[0]); i++)
	{
		gotoxy(x, y + i);
		if (i == n * 2) setColor(GREEN);//���õ� ��ȣ�� �޴��� �÷��� ���
		printf("%s", MainMenu[i]);
		if (i == n * 2) setColor(WHITE); //�÷��� �����·� ����
	}
	gotoxy(x, y + n * 2);//Ŀ���� ���õ� ��ȣ ��ġ��
}