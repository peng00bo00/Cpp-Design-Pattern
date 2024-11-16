#pragma once
#include <iostream>


class Beverage
{
public:
	virtual ~Beverage() { }
	virtual int getprice() = 0;
};

class FruitBeverage : public Beverage
{
	int getprice() {
		return 10;
	}
};