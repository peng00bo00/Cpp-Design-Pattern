#pragma once
#include <string>

using string = std::string;

class DailyHeaderData
{
public:
	DailyHeaderData(string strDepName, string strGenDate) :
		m_strDepName(strDepName), m_strGenData(strGenDate) { }

	string getDepName() {
		return m_strDepName;
	}

	string getExportDate() {
		return m_strGenData;
	}

private:
	string m_strDepName;
	string m_strGenData;
};

class DailyContentData
{
public:
	DailyContentData(string strContent, double dspendTime) :
		m_strContent(strContent), m_dspendTime(dspendTime) { }

	string getContent() {
		return m_strContent;
	}

	double getSpendTime() {
		return m_dspendTime;
	}

private:
	string m_strContent;
	double m_dspendTime;
};

class DailyFooterData
{
public:
	DailyFooterData(string strUserName) :
		m_strUserName(strUserName) { }

	string getUserName() {
		return m_strUserName;
	}

private:
	string m_strUserName;
};