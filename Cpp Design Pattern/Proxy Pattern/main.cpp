#include "WebAddr.h"

int main()
{
	WebAddr* wba1 = new WebAddr_Shopping();
	WebAddr* wba2 = new WebAddr_Video();

	WebAddrProxy* wbaproxy1 = new WebAddrProxy(wba1);
	WebAddrProxy* wbaproxy2 = new WebAddrProxy(wba2);

	wbaproxy1->visit();
	wbaproxy2->visit();

	delete wba1;
	delete wba2;
	delete wbaproxy1;
	delete wbaproxy2;

	return 0;
}