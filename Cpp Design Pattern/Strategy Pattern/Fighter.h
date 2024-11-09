#pragma once
#include "ItemStrategy.h"


class Fighter
{
public:
	Fighter(int life, int magic, int attack)
		: m_life(life), m_magic(magic), m_attack(attack) { }
	
	virtual ~Fighter() { }

	void SetItemStrategy(ItemStrategy* strategy) { itemstrategy = strategy;  }
	void UseItem() { itemstrategy->UseItem(this); }

	int GetLife() { return m_life;  }
	void SetLife(int life) { m_life = life; }

protected:
	int m_life;
	int m_magic;
	int m_attack;

private:
	ItemStrategy* itemstrategy = nullptr;
};

class F_Warrior : public Fighter
{
public:
	F_Warrior(int life, int magic, int attack)
		: Fighter(life, magic, attack) { }
};

class F_Mage : public Fighter
{
public:
	F_Mage(int life, int magic, int attack)
		: Fighter(life, magic, attack) { }
};

//enum class ItemAddLife
//{
//	LF_BXD,
//	LF_DHD,
//	LF_SHD,
//};