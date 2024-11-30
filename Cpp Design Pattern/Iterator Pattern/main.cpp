#include "myIter.h"
#include <iostream>

int main() {
	myContainer<int>* pcontainer = new myVector<int>();
	myIter<int>* iter = pcontainer->CreateIterator();

	// loop over the container
	int idx = 0;
	for (iter->First(); !iter->IsDone(); iter->Next()) {
		std::cout << "The " << idx << " element is: " << iter->CurrentItem() << std::endl;
		idx++;
	}

	delete iter;
	delete pcontainer;

	return 0;
}