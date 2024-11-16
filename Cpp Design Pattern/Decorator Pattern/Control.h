#pragma once
#include <iostream>


class Control
{
public:
	virtual ~Control() { };
	virtual void draw() = 0;
};

class ListControl : public Control
{
public:
	virtual void draw() {
		std::cout << "Drawing a list control..." << std::endl;
	}
};

