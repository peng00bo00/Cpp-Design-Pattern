#pragma once
#include "Monster.h"

class M_ParFactory
{
public:
	virtual Monster* createMonster() = 0;
	virtual ~M_ParFactory() { }
};

class M_UndeadFactory : public M_ParFactory
{
public:
	virtual Monster* createMonster() {
		return new M_Undead(300, 50, 80);
	}
};

class M_ElementFactory : public M_ParFactory
{
public:
	virtual Monster* createMonster() {
		return new M_Element(200, 80, 100);
	}
};

class M_MechanicFactory : public M_ParFactory
{
public:
	virtual Monster* createMonster() {
		return new M_Mechanic(400, 0, 110);
	}
};

Monster* Gbl_CreateMonster(M_ParFactory* factory);