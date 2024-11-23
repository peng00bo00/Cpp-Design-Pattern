#include "Cook.h"
#include "Command.h"
#include "Waiter.h"

int main() {
	Cook cook;

	Command* pcmd1 = new CommandFish(&cook);
	Command* pcmd2 = new CommandMeat(&cook);

	Waiter* pwaiter = new Waiter;
	pwaiter->AddCommand(pcmd1);
	pwaiter->AddCommand(pcmd2);

	pwaiter->Notify();

	delete pcmd1;
	delete pcmd2;
	delete pwaiter;

	return 0;
}