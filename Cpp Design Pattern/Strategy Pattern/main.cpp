#include <iostream>
#include "ItemStrategy.h"
#include "Fighter.h"

int main() {
	Fighter* prole_war = new F_Warrior(1000, 0, 200);
	std::cout << "Current HP: " << prole_war->GetLife() << std::endl;
	std::cout << "=================================================" << std::endl;

	std::cout << "Using DHD..." << std::endl;
	ItemStrategy* strategy = new ItemStrategy_DHD();
	prole_war->SetItemStrategy(strategy);
	prole_war->UseItem();
	std::cout << "Current HP: " << prole_war->GetLife() << std::endl;
	std::cout << "=================================================" << std::endl;

	std::cout << "Using BXD..." << std::endl;
	ItemStrategy* strategy2 = new ItemStrategy_BXD();
	prole_war->SetItemStrategy(strategy2);
	prole_war->UseItem();
	std::cout << "Current HP: " << prole_war->GetLife() << std::endl;

	delete strategy;
	delete strategy2;
	delete prole_war;

	return 0;
}