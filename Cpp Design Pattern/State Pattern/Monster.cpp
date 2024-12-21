#include "Monster.h"
#include "MonsterStatus.h"

Monster::Monster(int life) : m_life(life), m_pState(nullptr)
{
	m_pState = MonsterStatus_Feroc::getInstance();
}

Monster::~Monster() { }

void Monster::Attacked(int power)
{
	m_pState->Attacked(power, this);
}