#pragma once

class Fighter;

class ItemStrategy
{
public:
	virtual void UseItem(Fighter* mainobj) = 0;
	virtual ~ItemStrategy() { }
};

class ItemStrategy_BXD : public ItemStrategy
{
public:
	virtual void UseItem(Fighter* mainobj);
};

class ItemStrategy_DHD : public ItemStrategy
{
public:
	virtual void UseItem(Fighter* mainobj);
};

class ItemStrategy_SHD : public ItemStrategy
{
public:
	virtual void UseItem(Fighter* mainobj);
};