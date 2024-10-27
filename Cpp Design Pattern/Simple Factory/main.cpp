#include <iostream>
#include "Monster.h"

int main() {
	MonsterFactory facobj;
	Monster* pM1 = facobj.createMonster("udd");
	Monster* pM2 = facobj.createMonster("elm");
	Monster* pM3 = facobj.createMonster("mec");

	delete pM1;
	delete pM2;
	delete pM3;

	return 0;
}