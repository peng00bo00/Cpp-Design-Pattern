#pragma once
#include "LogToFile.h"
#include <iostream>

class LogToDataBase
{
public:
	virtual void initdb() = 0;
	virtual void writetodb(const char* pcontent) = 0;
	virtual void readfromdb() = 0;
	virtual void closedb() = 0;

	virtual ~LogToDataBase() {}
};

class LogAdapter : public LogToDataBase
{
public:
	LogAdapter(LogToFile* pfile) {
		m_pfile = pfile;
	}

	void initdb()
	{
		std::cout << "Adapting LogToFile::initfile()" << std::endl;
		m_pfile->initfile();
	}

	void writetodb(const char* pcontent)
	{
		std::cout << "Adapting LogToFile::writefile()" << std::endl;
		m_pfile->writetofile(pcontent);
	}

	void readfromdb()
	{
		std::cout << "Adapting LogToFile::readfromfile()" << std::endl;
		m_pfile->readfromfile();
	}

	void closedb()
	{
		std::cout << "Adapting LogToFile::closefile()" << std::endl;
		m_pfile->closefile();
	}

private:
	LogToFile* m_pfile;
};