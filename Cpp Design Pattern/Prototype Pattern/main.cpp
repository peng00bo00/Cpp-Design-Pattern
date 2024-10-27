#include <iostream>
#include "Monster.h"

int main() {
	M_Mechanic myPropMecMonster(400, 0, 100);
	Monster* pmyPropEleMonster = new M_Element(200, 80, 100);

	Monster* p_CloneObj1 = myPropMecMonster.clone();
	Monster* p_CloneObj2 = pmyPropEleMonster->clone();

	delete pmyPropEleMonster;
	delete p_CloneObj1;
	delete p_CloneObj2;

	return 0;
}