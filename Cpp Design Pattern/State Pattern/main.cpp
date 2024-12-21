#include "Monster.h"
#include "MonsterStatus.h"

int main() {
	Monster monster(500);
	monster.Attacked(20);
	monster.Attacked(100);
	monster.Attacked(200);
	monster.Attacked(170);
	monster.Attacked(100);
	monster.Attacked(100);

	return 0;
}