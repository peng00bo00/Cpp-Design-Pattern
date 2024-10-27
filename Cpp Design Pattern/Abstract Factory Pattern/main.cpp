#include <iostream>
#include "Monster.h"
#include "MonsterFactory.h"
#include "Doll.h"
#include "DollFactory.h"

int main() {
	M_ParFactory* p_mou_fy = new M_Factory_Mountain();
	Monster* pM1 = p_mou_fy->createMonster_Element();

	M_ParFactory* p_twn_fy = new M_Factory_Town();
	Monster* pM2 = p_twn_fy->createMonster_Undead();
	Monster* pM3 = p_twn_fy->createMonster_Mechanic();

	delete p_mou_fy;
	delete p_twn_fy;

	delete pM1;
	delete pM2;
	delete pM3;

	std::cout << "=========================================================" << std::endl;

	//====================================================================================
	AbstractFactory* pChinaFactory = new ChinaFactory();

	Body* pChinaBody = pChinaFactory->createBody();
	Cloth* pChinaCloth = pChinaFactory->createCloth();
	Shoes* pChinaShoes = pChinaFactory->createShoes();

	Doll* pdb1obj = new Doll(pChinaBody, pChinaCloth, pChinaShoes);
	pdb1obj->Assemble();

	std::cout << "=========================================================" << std::endl;

	//====================================================================================
	AbstractFactory* pJapanFactory = new JapanFactory();
	AbstractFactory* pAmericaFactory = new AmericaFactory();

	Body* pChinaBody2 = pChinaFactory->createBody();
	Cloth* pJapanCloth = pJapanFactory->createCloth();
	Shoes* pAmericaShoes = pAmericaFactory->createShoes();

	Doll* pdb2obj = new Doll(pChinaBody2, pJapanCloth, pAmericaShoes);
	pdb2obj->Assemble();


	delete pdb1obj;
	delete pChinaBody;
	delete pChinaCloth;
	delete pChinaShoes;
	delete pChinaFactory;

	delete pdb2obj;
	delete pChinaBody2;
	delete pJapanCloth;
	delete pAmericaShoes;
	delete pJapanFactory;
	delete pAmericaFactory;

	return 0;
}