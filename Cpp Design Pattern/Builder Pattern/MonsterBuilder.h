#pragma once
#include "Monster.h"
#include <string>
#include <iostream>

class MonsterBuilder
{
public:
	virtual ~MonsterBuilder() { }

	void Assemble(std::string strmodelno) {
		LoadTrunkModel(strmodelno.substr(4, 3));
		LoadHeadModel(strmodelno.substr(7, 3));
		LoadLimbsModel(strmodelno.substr(10, 3));
	}

	virtual void LoadTrunkModel(std::string strno) = 0;
	virtual void LoadHeadModel(std::string strno) = 0;
	virtual void LoadLimbsModel(std::string strno) = 0;

	Monster* GetResult() {
		return m_pMonster;
	}

protected:
	Monster* m_pMonster;
};

class M_UndeadBuilder : public MonsterBuilder
{
public:
	M_UndeadBuilder() {
		m_pMonster = new M_Undead();
	}

	void LoadTrunkModel(std::string strno) override {
		std::cout << "Loading the Trunk Model for an Undead Monster." << std::endl;
	}

	void LoadHeadModel(std::string strno) override {
		std::cout << "Loading the Head Model for an Undead Monster." << std::endl;
	}

	void LoadLimbsModel(std::string strno) override {
		std::cout << "Loading the Limbs Model for an Undead Monster." << std::endl;
	}
};

class M_ElementBuilder : public MonsterBuilder
{
public:
	M_ElementBuilder() {
		m_pMonster = new M_Element();
	}

	void LoadTrunkModel(std::string strno) override {
		std::cout << "Loading the Trunk Model for an Element Monster." << std::endl;
	}

	void LoadHeadModel(std::string strno) override {
		std::cout << "Loading the Head Model for an Element Monster." << std::endl;
	}

	void LoadLimbsModel(std::string strno) override {
		std::cout << "Loading the Limbs Model for an Element Monster." << std::endl;
	}
};

class M_MechanicBuilder : public MonsterBuilder
{
public:
	M_MechanicBuilder() {
		m_pMonster = new M_Mechanic();
	}

	void LoadTrunkModel(std::string strno) override {
		std::cout << "Loading the Trunk Model for a Mechanic Monster." << std::endl;
	}

	void LoadHeadModel(std::string strno) override {
		std::cout << "Loading the Head Model for a Mechanic Monster." << std::endl;
	}

	void LoadLimbsModel(std::string strno) override {
		std::cout << "Loading the Limbs Model for a Mechanic Monster." << std::endl;
	}
};