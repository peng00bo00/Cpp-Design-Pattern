#pragma once
#include <iostream>

class Fighter
{
public:
	Fighter(int life, int magic, int attack) : 
		m_life(life), m_magic(magic), m_attack(attack){ }
	virtual ~Fighter() { }

	void JN_Burn();

private:
	virtual bool canUseJN() = 0;
	virtual void effect_enemy() = 0;
	virtual void effect_self() = 0;
	void play_effect();

protected:
	int m_life;
	int m_magic;
	int m_attack;
};

class F_Warrior : public Fighter
{
public:
	F_Warrior(int life, int magic, int attack) : Fighter(life, magic, attack) { }

private:
	bool canUseJN();
	void effect_enemy();
	void effect_self();
};

class F_Mega : public Fighter
{
public:
	F_Mega(int life, int magic, int attack) : Fighter(life, magic, attack) { }

private:
	bool canUseJN();
	void effect_enemy();
	void effect_self();
};