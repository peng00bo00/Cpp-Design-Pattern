#pragma once
#include <iostream>

class MonsterStatus;

class Monster
{
public:
	Monster(int life);
	~Monster();

public:
	void Attacked(int power);
	
	int GetLife() {
		return m_life;
	}

	void SetLife(int life) {
		m_life = life;
	}

	MonsterStatus* getCurrentState() {
		return m_pState;
	}

	void setCurrentState(MonsterStatus* pstate) {
		m_pState = pstate;
	}

private:
	int m_life;
	MonsterStatus* m_pState;
};

