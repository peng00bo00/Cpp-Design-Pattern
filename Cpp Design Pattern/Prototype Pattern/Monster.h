#pragma once
#include <iostream>
#include <string>

class Monster
{
public:
	Monster(int life, int magic, int attack) :
		m_life(life), m_magic(magic), m_attack(attack) { }
	virtual ~Monster() { }

	virtual Monster* clone() = 0;

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

	M_Undead(const M_Undead& that) : Monster(that) {
		std::cout << "An Undead Monster is created through copy constructor." << std::endl;
	}

	virtual Monster* clone() {
		return new M_Undead(*this);
	}
};

class M_Element : public Monster
{
public:
	M_Element(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "An Element Monster is created." << std::endl;
	}

	M_Element(const M_Element& that) : Monster(that) {
		std::cout << "An Element Monster is created through copy constructor." << std::endl;
	}

	virtual Monster* clone() {
		return new M_Element(*this);
	}
};

class M_Mechanic : public Monster
{
public:
	M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack) {
		std::cout << "A Mechanic Monster is created." << std::endl;
	}

	M_Mechanic(const M_Mechanic& that) : Monster(that) {
		std::cout << "A Mechanic Monster is created through copy constructor." << std::endl;
	}

	virtual Monster* clone() {
		return new M_Mechanic(*this);
	}
};