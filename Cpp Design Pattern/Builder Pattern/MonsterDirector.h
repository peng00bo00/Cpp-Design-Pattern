#pragma once
#include "Monster.h"
#include "MonsterBuilder.h"

class MonsterDirector
{
public:
	MonsterDirector(MonsterBuilder *pMonsterBuilder) :
		m_pMonsterBuilder(pMonsterBuilder) { }

	void SetBuilder(MonsterBuilder* pMonsterBuilder) {
		m_pMonsterBuilder = pMonsterBuilder;
	}

	Monster* Construct(std::string strmodelno) {
		m_pMonsterBuilder->Assemble(strmodelno);
		return m_pMonsterBuilder->GetResult();
	}

private:
	MonsterBuilder* m_pMonsterBuilder;
};