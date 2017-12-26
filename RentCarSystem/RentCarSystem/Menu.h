#pragma once
#ifndef __MENU_H__
#define __MENU_H__

namespace CAR_DISPLAY {
	int Menu();
	int Menu(int flag);
	void printMenu(int n, int & y);
	void printMenu(int n, int & y, int flag);
}



const int UP = 72;
const int DOWN = 80;
const int ESC = 27;
const int ENTER = 13;
const int GREEN = 10;
const int WHITE = 15;

#endif