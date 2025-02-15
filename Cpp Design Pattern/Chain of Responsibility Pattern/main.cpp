#include "RaiseRequest.h"
#include "ParSalApprover.h"
#include <iostream>

int main() {
	ParSalApprover* pzzlinkobj1 = new depManager_SA();
	ParSalApprover* pzzlinkobj2 = new CTO_SA();
	ParSalApprover* pzzlinkobj3 = new genmMnager_SA();

	pzzlinkobj1->setNextChain(pzzlinkobj2);
	pzzlinkobj2->setNextChain(pzzlinkobj3);

	RaiseRequest mep1Req("Zhang", 15000);
	RaiseRequest mep2Req("Li",    3500);
	RaiseRequest mep3Req("Wang",  800);

	pzzlinkobj1->processRequest(mep1Req);
	pzzlinkobj1->processRequest(mep2Req);
	pzzlinkobj1->processRequest(mep3Req);

	delete pzzlinkobj3;
	delete pzzlinkobj2;
	delete pzzlinkobj1;

	return 0;
}