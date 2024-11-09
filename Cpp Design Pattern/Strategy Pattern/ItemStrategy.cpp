#include "ItemStrategy.h"
#include "Fighter.h"

void ItemStrategy_BXD::UseItem(Fighter* mainobj) {
	mainobj->SetLife(mainobj->GetLife() + 200);
}

void ItemStrategy_DHD::UseItem(Fighter* mainobj) {
	mainobj->SetLife(mainobj->GetLife() + 300);
}

void ItemStrategy_SHD::UseItem(Fighter* mainobj) {
	mainobj->SetLife(mainobj->GetLife() + 500);
}