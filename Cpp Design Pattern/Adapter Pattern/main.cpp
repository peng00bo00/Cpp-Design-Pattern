#include "LogToFile.h"
#include "LogToDataBase.h"

int main()
{
	LogToFile* plog = new LogToFile();
	LogToDataBase* plogdb = new LogAdapter(plog);

	plogdb->initdb();
	plogdb->writetodb("Writing a log to database.");
	plogdb->readfromdb();
	plogdb->closedb();

	delete plog;
	delete plogdb;

	return 0;
}