#pragma once
#include <iostream>
#include <string>

class Monster
{
public:
	Monster(int life, int magic, int attack) :
		m_life(life), m_magic(magic), m_attack(attack) { }
	virtual ~Monster() { }

protected:
	int m_life;
	int m_magic;
	int m_attack;
};

//====================================================================================

class M_Undead_Swamp : public Monster
{
public:
	M_Undead_Swamp(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Swamp Undead Monster is created." << std::endl;
	}
};

class M_Element_Swamp : public Monster
{
public:
	M_Element_Swamp(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Swamp Element Monster is created." << std::endl;
	}
};

class M_Mechanic_Swamp : public Monster
{
public:
	M_Mechanic_Swamp(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Swamp Mechanic Monster is created." << std::endl;
	}
};

//====================================================================================

class M_Undead_Mountain : public Monster
{
public:
	M_Undead_Mountain(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Mountain Undead Monster is created." << std::endl;
	}
};

class M_Element_Mountain : public Monster
{
public:
	M_Element_Mountain(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Mountain Element Monster is created." << std::endl;
	}
};

class M_Mechanic_Mountain : public Monster
{
public:
	M_Mechanic_Mountain(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Mountain Mechanic Monster is created." << std::endl;
	}
};

//====================================================================================

class M_Undead_Town : public Monster
{
public:
	M_Undead_Town(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Town Undead Monster is created." << std::endl;
	}
};

class M_Element_Town : public Monster
{
public:
	M_Element_Town(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Town Element Monster is created." << std::endl;
	}
};

class M_Mechanic_Town : public Monster
{
public:
	M_Mechanic_Town(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Town Mechanic Monster is created." << std::endl;
	}
};