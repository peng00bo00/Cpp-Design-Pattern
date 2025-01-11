#include "Common.h"
#include "Ctrl.h"
#include "Mediator.h"


int main() {
	contrMediator mymedia;
	mymedia.createCtrl();

	std::cout << "==================== LogIn button is selected. ====================" << std::endl;
	mymedia.mp_rbtn2->Changed();
}