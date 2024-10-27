#include "MonsterFactory.h"

Monster* Gbl_CreateMonster(M_ParFactory* factory) {
	return factory->createMonster();
}