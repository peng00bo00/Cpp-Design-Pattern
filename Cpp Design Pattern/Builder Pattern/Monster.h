#pragma once

class Monster
{
public:
	virtual ~Monster() { }
};

class M_Undead : public Monster
{
};

class M_Element : public Monster
{
};

class M_Mechanic : public Monster
{
};