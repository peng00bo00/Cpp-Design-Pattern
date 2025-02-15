#include <iostream>
#include "Fighter.h"

int main() {
	Fighter* p_fighter = new Fighter(800, 200, 300);
	p_fighter->displayInfo();

	// create a memo
	FighterMemento* p_fighterMemo = p_fighter->createMemento();

	std::cout << "After a long fight..." << std::endl;
	p_fighter->setToDead();
	p_fighter->displayInfo();

	std::cout << "Restore from memo..." << std::endl;
	p_fighter->restoreMemento(p_fighterMemo);
	p_fighter->displayInfo();

	delete p_fighterMemo;
	delete p_fighter;

	return 0;
}