#pragma once
#ifndef __MENU_H__
#define __MENU_H__

#include <list>
#include "Car.h"

namespace CAR_DISPLAY {
	int Menu();
	list<Car>::iterator Menu(int flag, list<Car> & carList);
	void printMenu(int n, int & y);
	void printMenu(int n, int & y, int &j, list<Car> & carList);
}

const int UP = 72;
const int DOWN = 80;
const int ESC = 27;
const int ENTER = 13;
const int GREEN = 10;
const int WHITE = 15;

#endif