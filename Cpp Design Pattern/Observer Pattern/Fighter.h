#pragma once
#include <string>
#include <iostream>
#include "Notifier.h"

class Fighter
{
public:
	Fighter(int tmpID, std::string tmpName)
		: m_iPlayerID(tmpID), m_sPlayerName(tmpName) {
		m_iFamilyID = -1;
	}

	virtual ~Fighter() { }

	void SetFamilyID(int tmpID) {
		m_iFamilyID = tmpID;
	}

	int GetFamilyID() { return m_iFamilyID; }

	void SayWords(std::string tmpContent, Notifier* notifier) {
		notifier->notify(this, tmpContent);
	}

	virtual void NotifyWords(Fighter* talker, std::string tmpContent) {
		std::cout << "Player: " << "[" << m_sPlayerName << "]" << " receives message "
			<< "\"" << tmpContent << "\" "
			<< "from player " << "[" << talker->m_sPlayerName << "]" << std::endl;
	}

private:
	int m_iPlayerID;
	std::string m_sPlayerName;

	int m_iFamilyID;
};

class F_Warrior : public Fighter
{
public:
	F_Warrior(int tmpID, std::string tmpName)
		: Fighter(tmpID, tmpName) { }
};

class F_Mage : public Fighter
{
public:
	F_Mage(int tmpID, std::string tmpName)
		: Fighter(tmpID, tmpName) { }
};
