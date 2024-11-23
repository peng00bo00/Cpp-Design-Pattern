#pragma once
#include "Cook.h"


class Command
{
public:
	Command(Cook* pcook) {
		m_pcook = pcook;
	}

	virtual ~Command() { }
	virtual void Excute() = 0;

protected:
	Cook* m_pcook;
};

class CommandFish : public Command
{
public:
	CommandFish(Cook* pcook) : Command(pcook) { }

	void Excute() {
		m_pcook->cook_fish();
	}
};

class CommandMeat : public Command
{
public:
	CommandMeat(Cook* pcook) : Command(pcook) {}

	void Excute() {
		m_pcook->cook_meat();
	}
};