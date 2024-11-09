#pragma once
#include <string>
#include <map>
#include <list>

class Fighter;

class Notifier
{
public:
	virtual void addToList(Fighter* player) = 0;
	virtual void removeFromList(Fighter* player) = 0;
	virtual void notify(Fighter* player, std::string tmpContent) = 0;
	virtual ~Notifier() { }
};

class TalkNotifier : public Notifier
{
public:
	void addToList(Fighter* player);
	void removeFromList(Fighter* player);
	void notify(Fighter* player, std::string tmpContent);

private:
	std::map<int, std::list<Fighter*>> m_familyList;
};
