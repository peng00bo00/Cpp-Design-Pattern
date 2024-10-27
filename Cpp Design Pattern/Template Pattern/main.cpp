#include <iostream>
#include "Fighter.h"

int main() {
	Fighter* prole_war = new F_Warrior(1000, 0, 200);
	prole_war->JN_Burn();

	std::cout << "----------------------------------------" << std::endl;

	Fighter* prole_mag = new F_Mega(800, 200, 300);
	prole_mag->JN_Burn();

	delete prole_war;
	delete prole_mag;

	return 0;
}