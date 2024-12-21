#include "MonsterStatus.h"

void MonsterStatus_Feroc::Attacked(int power, Monster* mainobj)
{
	int orglife = mainobj->GetLife();

	if ((orglife - power) > 400) {
		mainobj->SetLife(orglife - power);
		std::cout << "The monster is in Frenzy State." << std::endl;
	}
	else {
		mainobj->setCurrentState(MonsterStatus_Worr::getInstance());
		mainobj->getCurrentState()->Attacked(power, mainobj);
	}
}

void MonsterStatus_Worr::Attacked(int power, Monster* mainobj)
{
	int orglife = mainobj->GetLife();

	if ((orglife - power) > 100) {
		mainobj->SetLife(orglife - power);
		std::cout << "The monster is in Worried State." << std::endl;
	}
	else {
		mainobj->setCurrentState(MonsterStatus_Fear::getInstance());
		mainobj->getCurrentState()->Attacked(power, mainobj);
	}
}

void MonsterStatus_Fear::Attacked(int power, Monster* mainobj)
{
	int orglife = mainobj->GetLife();

	if ((orglife - power) > 0) {
		mainobj->SetLife(orglife - power);
		std::cout << "The monster is in Fearful State." << std::endl;
	}
	else {
		mainobj->setCurrentState(MonsterStatus_Dead::getInstance());
		mainobj->getCurrentState()->Attacked(power, mainobj);
	}
}

void MonsterStatus_Dead::Attacked(int power, Monster* mainobj)
{
	int orglife = mainobj->GetLife();

	if (orglife > 0)
	{
		mainobj->SetLife(orglife - power);
	}

	std::cout << "The monster is Dead." << std::endl;
}