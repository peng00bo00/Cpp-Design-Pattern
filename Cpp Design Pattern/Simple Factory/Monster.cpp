#include "Monster.h"

Monster* MonsterFactory::createMonster(std::string strmontype) {
	Monster* prtnobj = nullptr;

	if (strmontype == "udd") {
		prtnobj = new M_Undead(300, 50, 80);
	}
	else if (strmontype == "elm") {
		prtnobj = new M_Element(200, 80, 100);
	}
	else if (strmontype == "mec") {
		prtnobj = new M_Mechanic(400, 0, 110);
	}

	return prtnobj;
}