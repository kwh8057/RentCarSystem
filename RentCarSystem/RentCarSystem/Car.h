#pragma once
#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
#include <string.h>

using namespace std;

class Car {
private:
	int carId;			// 차량 ID
	int rentalCost;		// 렌트비
	string carType;		// 차종
	string manufacturer;// 제조회사
	string color;		// 색상
	bool rentable = true;		// 대여 가능 여부

public:
	Car(int carId, int rentalCost, string carType, string manufacturer, string color);

	void checkInsurance();		// 보험 내역 확인
	void checkRepair();			// 정비 내역 확인

	int getCarId() { return this->carId; }
	int getRentalCost() { return this->rentalCost; }
	string getCarType() { return this->carType; }
	string getManufacturer() { return this->manufacturer; }
	string getColor() { return this->color; }
	bool getRentable() { return this->rentable; }
	void setRentable(bool rentable) { this->rentable = rentable; }
};

#endif
