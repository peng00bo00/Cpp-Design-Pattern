#pragma once
#include "Monster.h"

class M_ParFactory
{
public:
	virtual Monster* createMonster_Undead() = 0;
	virtual Monster* createMonster_Element() = 0;
	virtual Monster* createMonster_Mechanic() = 0;
	virtual ~M_ParFactory() { }
};

//====================================================================================

class M_Factory_Swamp : public M_ParFactory
{
public:
	virtual Monster* createMonster_Undead() {
		return new M_Undead_Swamp(300, 50, 120);
	}

	virtual Monster* createMonster_Element() {
		return new M_Element_Swamp(200, 80, 110);
	}

	virtual Monster* createMonster_Mechanic() {
		return new M_Mechanic_Swamp(400, 0, 90);
	}
};

class M_Factory_Mountain : public M_ParFactory
{
public:
	virtual Monster* createMonster_Undead() {
		return new M_Undead_Mountain(300, 50, 80);
	}

	virtual Monster* createMonster_Element() {
		return new M_Element_Mountain(200, 80, 100);
	}

	virtual Monster* createMonster_Mechanic() {
		return new M_Mechanic_Mountain(600, 0, 110);
	}
};

class M_Factory_Town : public M_ParFactory
{
public:
	virtual Monster* createMonster_Undead() {
		return new M_Undead_Town(300, 50, 80);
	}

	virtual Monster* createMonster_Element() {
		return new M_Element_Town(200, 80, 100);
	}

	virtual Monster* createMonster_Mechanic() {
		return new M_Mechanic_Town(400, 0, 110);
	}
};