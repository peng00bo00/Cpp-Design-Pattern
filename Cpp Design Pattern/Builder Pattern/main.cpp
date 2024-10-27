#include <string>
#include "Monster.h"
#include "MonsterBuilder.h"
#include "MonsterDirector.h"

int main() {
	MonsterBuilder* pMonsterBuilder = new M_UndeadBuilder();
	MonsterDirector* pDirector = new MonsterDirector(pMonsterBuilder);
	Monster* pMonster = pDirector->Construct("1234567890");

	delete pMonster;
	delete pDirector;
	delete pMonsterBuilder;

	return 0;
}