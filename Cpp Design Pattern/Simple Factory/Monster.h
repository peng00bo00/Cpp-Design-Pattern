#pragma once
#include <iostream>
#include <string>

class Monster
{
public:
	Monster(int life, int magic, int attack):
		m_life(life), m_magic(magic), m_attack(attack) { }
	virtual ~Monster() { }

protected:
	int m_life;
	int m_magic;
	int m_attack;
};

class M_Undead : public Monster
{
public:
	M_Undead(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "An Undead Monster is created." << std::endl;
	}
};

class M_Element : public Monster
{
public:
	M_Element(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "An Element Monster is created." << std::endl;
	}
};

class M_Mechanic : public Monster
{
public:
	M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Mechanic Monster is created." << std::endl;
	}
};

class MonsterFactory
{
public:
	static Monster* createMonster(std::string strmontype);
};