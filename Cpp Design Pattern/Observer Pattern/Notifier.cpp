#include "Notifier.h"
#include "Fighter.h"


void TalkNotifier::addToList(Fighter* player) {
	int tmpFamilyID = player->GetFamilyID();
	if (tmpFamilyID != -1) {
		auto iter = m_familyList.find(tmpFamilyID);
		if (iter != m_familyList.end()) {
			iter->second.push_back(player);
		}
		else {
			std::list<Fighter*> tmpPlayerList;
			m_familyList.insert(std::make_pair(tmpFamilyID, tmpPlayerList));
			m_familyList[tmpFamilyID].push_back(player);
		}
	}
}

void TalkNotifier::removeFromList(Fighter* player) {
	int tmpFamilyID = player->GetFamilyID();
	if (tmpFamilyID != -1) {
		auto iter = m_familyList.find(tmpFamilyID);
		if (iter != m_familyList.end()) {
			m_familyList[tmpFamilyID].remove(player);
		}
	}
}

void TalkNotifier::notify(Fighter* player, std::string tmpContent) {
	int tmpFamilyID = player->GetFamilyID();
	if (tmpFamilyID != -1) {
		auto itermap = m_familyList.find(tmpFamilyID);
		if (itermap != m_familyList.end()) {
			for (auto iterlist = itermap->second.begin(); iterlist != itermap->second.end(); ++iterlist) {
				(*iterlist)->NotifyWords(player, tmpContent);
			}
		}
	}
}