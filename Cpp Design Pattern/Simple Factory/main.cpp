#include <iostream>
#include "Monster.h"

int main() {
	Monster* pM1 = MonsterFactory::createMonster("udd");
	Monster* pM2 = MonsterFactory::createMonster("elm");
	Monster* pM3 = MonsterFactory::createMonster("mec");

	delete pM1;
	delete pM2;
	delete pM3;

	return 0;
}