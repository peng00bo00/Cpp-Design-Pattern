#pragma once
#include <iostream>
#include "Monster.h"

class MonsterStatus
{
public:
	virtual void Attacked(int power, Monster* mainobj) = 0;
	virtual ~MonsterStatus() { }
};

class MonsterStatus_Feroc : public MonsterStatus
{
public:
	static MonsterStatus_Feroc* getInstance()
	{
		static MonsterStatus_Feroc instance;
		return &instance;
	}

	virtual void Attacked(int power, Monster* mainobj);
};

class MonsterStatus_Worr : public MonsterStatus
{
public:
	static MonsterStatus_Worr* getInstance()
	{
		static MonsterStatus_Worr instance;
		return &instance;
	}

	virtual void Attacked(int power, Monster* mainobj);
};

class MonsterStatus_Fear : public MonsterStatus
{
public:
	static MonsterStatus_Fear* getInstance()
	{
		static MonsterStatus_Fear instance;
		return &instance;
	}

	virtual void Attacked(int power, Monster* mainobj);
};

class MonsterStatus_Dead : public MonsterStatus
{
public:
	static MonsterStatus_Dead* getInstance()
	{
		static MonsterStatus_Dead instance;
		return &instance;
	}

	virtual void Attacked(int power, Monster* mainobj);
};