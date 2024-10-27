#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "DailyReportData.h"

class FileBuilder
{
public:
	virtual ~FileBuilder() { };

	virtual void buildHeader(DailyHeaderData& dailyheaderobj) = 0;
	virtual void buildBody(std::vector<DailyContentData*>& vec_dailycontobj) = 0;
	virtual void buildFooter(DailyFooterData& dailyfooterobj) = 0;

	string GetResult() {
		return m_strResult;
	}

protected:
	string m_strResult;
};

class TxtFileBuilder : public FileBuilder
{
public:
	void buildHeader(DailyHeaderData& dailyheaderobj) override {
		m_strResult += dailyheaderobj.getDepName() + "," + dailyheaderobj.getExportDate() + "\n";
	}

	void buildBody(std::vector<DailyContentData*>& vec_dailycontobj) override {
		for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter) {
			std::ostringstream oss;
			oss << (*iter)->getSpendTime();
			m_strResult += (*iter)->getContent() + ":(花费的时间: " + oss.str() + " 小时)" + "\n";
		}
	}

	void buildFooter(DailyFooterData& dailyfooterobj) override {
		m_strResult += "报告人: " + dailyfooterobj.getUserName() + "\n";
	}
};

class XmlFileBuilder : public FileBuilder
{
public:
	void buildHeader(DailyHeaderData& dailyheaderobj) override {
		m_strResult += "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
		m_strResult += "<DailyReport>\n";

		m_strResult += "<Header>\n";
		m_strResult += "<DepName>" + dailyheaderobj.getDepName() + "</DepName>\n";
		m_strResult += "<GenDate>" + dailyheaderobj.getExportDate() + "</GenDate>\n";
		m_strResult += "</Header>\n";
	}

	void buildBody(std::vector<DailyContentData*>& vec_dailycontobj) override {
		m_strResult += "<Body>\n";
		for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter) {
			std::ostringstream oss;
			oss << (*iter)->getSpendTime();
			m_strResult += "<Content>" + (*iter)->getContent() + "</Content>\n";
			m_strResult += "<SpendTime>花费的时间: " + oss.str() + " 小时" + "</SpendTime>\n";
		}
		m_strResult += "</Body>\n";
	}

	void buildFooter(DailyFooterData& dailyfooterobj) override {
		m_strResult += "<Footer>\n";
		m_strResult += "<UserName>报告人: " + dailyfooterobj.getUserName() + "</UserName>\n";
		m_strResult += "</Footer>\n";

		m_strResult += "</DailyReport>\n";
	}
};

class FileDirector
{
public:
	FileDirector(FileBuilder* pBuilder) : m_pFileBuilder(pBuilder) { }

	string Construct(DailyHeaderData& dailyheaderobj, 
					 std::vector<DailyContentData*>& vec_dailycontobj,
					 DailyFooterData& dailyfooterobj) {
		m_pFileBuilder->buildHeader(dailyheaderobj);
		m_pFileBuilder->buildBody(vec_dailycontobj);
		m_pFileBuilder->buildFooter(dailyfooterobj);

		return m_pFileBuilder->GetResult();
	}

private:
	FileBuilder* m_pFileBuilder;
};