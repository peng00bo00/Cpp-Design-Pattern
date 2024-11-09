#include "Fighter.h"
#include "Notifier.h"
#include <iostream>


int main() {
	// players
	Fighter* pplayerobj1 = new F_Warrior(10, "A");
	pplayerobj1->SetFamilyID(100);

	Fighter* pplayerobj2 = new F_Warrior(20, "B");
	pplayerobj2->SetFamilyID(100);

	Fighter* pplayerobj3 = new F_Mage(30, "C");
	pplayerobj3->SetFamilyID(100);

	Fighter* pplayerobj4 = new F_Mage(50, "D");
	pplayerobj4->SetFamilyID(200);

	// notifier
	Notifier* ptalknotify = new TalkNotifier();

	// add players to family list
	ptalknotify->addToList(pplayerobj1);
	ptalknotify->addToList(pplayerobj2);
	ptalknotify->addToList(pplayerobj3);
	ptalknotify->addToList(pplayerobj4);

	pplayerobj1->SayWords("Everyone get to the swamp. Ready to fight!", ptalknotify);

	ptalknotify->removeFromList(pplayerobj3);
	std::cout << "Player [C] just left the family." << std::endl;

	pplayerobj2->SayWords("Everyone follow the lead. Get to the swamp!", ptalknotify);

	delete pplayerobj1;
	delete pplayerobj2;
	delete pplayerobj3;
	delete pplayerobj4;
	
	delete ptalknotify;

	return 0;
}