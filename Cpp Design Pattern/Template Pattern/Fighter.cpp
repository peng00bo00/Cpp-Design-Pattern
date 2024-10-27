#include "Fighter.h"

void Fighter::JN_Burn()
{
	if (!canUseJN()) return;

	effect_enemy();
	effect_self();
	play_effect();
}

void Fighter::play_effect()
{
	std::cout << "The player casts the spell \"Burn\"." << std::endl;
}

bool F_Warrior::canUseJN()
{
	return m_life > 300;
}

void F_Warrior::effect_enemy()
{
	std::cout << "Warroir: Deal 500 HP damage to each enemy." << std::endl;
}

void F_Warrior::effect_self()
{
	std::cout << "Warroir: Use 300 HP." << std::endl;
	m_life -= 300;
}

bool F_Mega::canUseJN()
{
	return m_magic > 100;
}

void F_Mega::effect_enemy()
{
	std::cout << "Mega: Deal 650 HP damage to each enemy." << std::endl;
}

void F_Mega::effect_self()
{
	std::cout << "Mega: Use 100 MP." << std::endl;
	m_magic -= 100;
}