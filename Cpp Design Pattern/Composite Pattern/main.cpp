#include "FileSystem.h"
#include <iostream>

int main() {
	// create directories and files
	FileSystem* pdir1  = new Dir("root");
	FileSystem* pfile1 = new File("common.mk");
	FileSystem* pfile2 = new File("config.mk");
	FileSystem* pfile3 = new File("makefile");

	FileSystem* pdir2  = new Dir("app");
	FileSystem* pfile4 = new File("nginx.c");
	FileSystem* pfile5 = new File("ngx_conf.c");

	FileSystem* pdir3 = new Dir("signal");
	FileSystem* pfile6 = new File("ngx_signal.c");

	FileSystem* pdir4 = new Dir("include");
	FileSystem* pfile7 = new File("ngx_func.h");
	FileSystem* pfile8 = new File("ngx_signal.h");

	// create structures
	pdir1->Add(pfile1);
	pdir1->Add(pfile2);
	pdir1->Add(pfile3);
		
	pdir1->Add(pdir2);
	pdir2->Add(pfile4);
	pdir2->Add(pfile5);

	pdir1->Add(pdir3);
	pdir3->Add(pfile6);

	pdir1->Add(pdir4);
	pdir4->Add(pfile7);
	pdir4->Add(pfile8);

	// print the file system
	pdir1->ShowName(0);

	delete pfile8;
	delete pfile7;
	delete pdir4;

	delete pfile6;
	delete pdir3;

	delete pfile5;
	delete pfile4;
	delete pdir2;

	delete pfile3;
	delete pfile2;
	delete pfile1;
	delete pdir1;
}