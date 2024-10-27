#pragma once
#include "Doll.h"

class AbstractFactory
{
public:
	virtual Body* createBody() = 0;
	virtual Cloth* createCloth() = 0;
	virtual Shoes* createShoes() = 0;

	virtual ~AbstractFactory() { }
};

class ChinaFactory : public AbstractFactory
{
public:
	virtual Body* createBody() {
		return new China_Body();
	}

	virtual Cloth* createCloth() {
		return new China_Cloth();
	}

	virtual Shoes* createShoes() {
		return new China_Shoes();
	}
};

class JapanFactory : public AbstractFactory
{
public:
	virtual Body* createBody() {
		return new Japan_Body();
	}

	virtual Cloth* createCloth() {
		return new Japan_Cloth();
	}

	virtual Shoes* createShoes() {
		return new Japan_Shoes();
	}
};

class AmericaFactory : public AbstractFactory
{
public:
	virtual Body* createBody() {
		return new America_Body();
	}

	virtual Cloth* createCloth() {
		return new America_Cloth();
	}

	virtual Shoes* createShoes() {
		return new America_Shoes();
	}
};