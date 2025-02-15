#pragma once
#include <iostream>

class FighterMemento
{
private:
	FighterMemento(int life, int magic, int attack)
		: m_life(life), m_magic(magic), m_attack(attack) { }

private:
	friend class Fighter;
	
	int getLife() const { return m_life; }
	void setLife(int life) { m_life = life; }

	int getMagic() const { return m_magic; }
	void setMagic(int magic) { m_magic = magic; }

	int getAttack() const { return m_attack; }
	void setAttack(int attack) { m_attack = attack; }

private:
	int m_life;
	int m_magic;
	int m_attack;
};


class Fighter
{
public:
	Fighter(int life, int magic, int attack) : 
		m_life(life), m_magic(magic), m_attack(attack) { }

	FighterMemento* createMemento()
	{
		return new FighterMemento(m_life, m_magic, m_attack);
	}

	void restoreMemento(FighterMemento* pfm)
	{
		m_life = pfm->getLife();
		m_magic = pfm->getMagic();
		m_attack = pfm->getAttack();
	}

	void setToDead()
	{
		m_life = 0;
	}

	void displayInfo()
	{
		std::cout << "Current Life: " << m_life
			<< ", Current Magic: " << m_magic
			<< ", Current Attack: " << m_attack << std::endl;
	}

private:
	int m_life;
	int m_magic;
	int m_attack;
};

