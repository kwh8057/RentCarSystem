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

public:
	void checkInsurance();		// 보험 내역 확인
	void checkRepair();			// 정비 내역 확인
};

#endif