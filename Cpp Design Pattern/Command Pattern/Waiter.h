#pragma once
#include <list>
#include "Command.h"

class Waiter
{
public:
	void AddCommand(Command* pcommand) {
		m_commlist.push_back(pcommand);
	}

	void DelCommand(Command* pcommand) {
		m_commlist.remove(pcommand);
	}

	void Notify() {
		for (auto const pcommand : m_commlist) {
			pcommand->Excute();
		}
	}

private:
	std::list<Command*> m_commlist;
};

