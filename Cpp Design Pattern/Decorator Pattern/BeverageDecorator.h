#pragma once
#include "Beverage.h"


class BeverageDecorator : public Beverage
{
public:
	BeverageDecorator(Beverage* tmpbvg)
		: m_pbvg(tmpbvg) { }

	virtual int getprice() {
		return m_pbvg->getprice();
	}

private:
	Beverage* m_pbvg;
};

class SugarDec : public BeverageDecorator
{
public:
	SugarDec(Beverage* tmpbvg)
		: BeverageDecorator(tmpbvg) { }

	int getprice() {
		return BeverageDecorator::getprice() + 1;
	}
};

class MilkDec : public BeverageDecorator
{
public:
	MilkDec(Beverage* tmpbvg)
		: BeverageDecorator(tmpbvg) { }

	int getprice() {
		return BeverageDecorator::getprice() + 2;
	}
};

class BubbleDec : public BeverageDecorator
{
public:
	BubbleDec(Beverage* tmpbvg)
		: BeverageDecorator(tmpbvg) { }

	int getprice() {
		return BeverageDecorator::getprice() + 2;
	}
};