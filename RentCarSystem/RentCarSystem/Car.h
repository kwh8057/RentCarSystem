#pragma once
#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
#include <string.h>

using namespace std;

class Car {
private:
	int carId;			// ���� ID
	int rentalCost;		// ��Ʈ��
	string carType;		// ����
	string manufacturer;// ����ȸ��
	string color;		// ����

public:
	void checkInsurance();		// ���� ���� Ȯ��
	void checkRepair();			// ���� ���� Ȯ��
};

#endif