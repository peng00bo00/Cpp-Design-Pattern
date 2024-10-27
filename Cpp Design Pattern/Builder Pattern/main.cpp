#include <string>
#include <vector>
#include "Monster.h"
#include "MonsterBuilder.h"
#include "MonsterDirector.h"

#include "DailyReportData.h"
#include "DailyReportBuilder.h"

int main() {
	MonsterBuilder* pMonsterBuilder = new M_UndeadBuilder();
	MonsterDirector* pDirector = new MonsterDirector(pMonsterBuilder);
	Monster* pMonster = pDirector->Construct("1234567890");

	delete pMonster;
	delete pDirector;
	delete pMonsterBuilder;

	std::cout << "=========================================================" << std::endl;
	DailyHeaderData* pdhd = new DailyHeaderData("�з�һ��", "11��1��");

	DailyContentData* pdcd1 = new DailyContentData("���A��Ŀ�������������", 3.5);
	DailyContentData* pdcd2 = new DailyContentData("ȷ��B��Ŀ������ʹ�õĹ���", 4.5);
	std::vector<DailyContentData*> vec_dcd;
	vec_dcd.push_back(pdcd1);
	vec_dcd.push_back(pdcd2);

	DailyFooterData* pdfd = new DailyFooterData("С��");

	// FileBuilder* pfb = new TxtFileBuilder();
	FileBuilder* pfb = new XmlFileBuilder();
	FileDirector* pDtr = new FileDirector(pfb);
	std::cout << pDtr->Construct(*pdhd, vec_dcd, *pdfd) << std::endl;

	delete pdhd;
	for (auto iter = vec_dcd.begin(); iter != vec_dcd.end(); ++iter) {
		delete (*iter);
	}

	delete pdfd;

	delete pfb;
	delete pDtr;

	return 0;
}