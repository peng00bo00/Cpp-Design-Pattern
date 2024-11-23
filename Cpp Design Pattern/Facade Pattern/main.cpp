#include <iostream>
#include "HomeTheaterFacade.h"

int main() {
	HomeTheaterFacade htfacobj;

	std::cout << "Start watching movie---------------------" << std::endl;
	htfacobj.WatchMovie();

	std::cout << "Start playing games----------------------" << std::endl;
	htfacobj.PlayGame();

	return 0;
}