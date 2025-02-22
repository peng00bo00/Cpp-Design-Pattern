#include "Expression.h"
#include <string>
#include <map>
#include <iostream>

int main() {
	std::string strExp = "a-b+c+d";
	std::map<char, int> varmap;

	varmap.insert(std::make_pair('a', 7));
	varmap.insert(std::make_pair('b', 9));
	varmap.insert(std::make_pair('c', 3));
	varmap.insert(std::make_pair('d', 2));

	Expression* expression = analyse(strExp);
	int result = expression->interpret(varmap);

	std::cout << "The evalution of string \'" << strExp << "\' is: "
		<< result << std::endl;

	release(expression);

	return 0;
}