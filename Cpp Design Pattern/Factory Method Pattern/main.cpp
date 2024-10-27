#include <iostream>
#include "Monster.h"
#include "MonsterFactory.h"

int main() {
	M_ParFactory* p_ud_fy = new M_UndeadFactory();
	Monster* pM1 = Gbl_CreateMonster(p_ud_fy);

	M_ParFactory* p_elm_fy = new M_ElementFactory();
	Monster* pM2 = Gbl_CreateMonster(p_elm_fy);

	M_ParFactory* p_mec_fy = new M_MechanicFactory();
	Monster* pM3 = Gbl_CreateMonster(p_mec_fy);

	delete p_ud_fy;
	delete p_elm_fy;
	delete p_mec_fy;

	delete pM1;
	delete pM2;
	delete pM3;

	return 0;
}