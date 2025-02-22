#include <stack>
#include <string>
#include "Expression.h"


Expression* analyse(std::string strExp) {
	std::stack<Expression*> expStack;

	Expression* left = nullptr;
	Expression* right = nullptr;

	int icount = 1;
	for (size_t i = 0; i < strExp.size(); i++)
	{
		switch (strExp[i]) {
		case '+':
			left = expStack.top();
			++i;
			right = new VarExpression(strExp[i], icount++, 'v');
			expStack.push(new AddExpression(left, right, icount++, '+'));

			break;
		case '-':
			left = expStack.top();
			++i;
			right = new VarExpression(strExp[i], icount++, 'v');
			expStack.push(new SubExpression(left, right, icount++, '-'));

			break;
		default:
			expStack.push(new VarExpression(strExp[i], icount++, 'v'));
			break;
		}
	}

	Expression* expression = expStack.top();
	return expression;
}

void release(Expression* expression) {
	SymbolExpression* pSE = dynamic_cast<SymbolExpression*>(expression);

	if (pSE) {
		release(pSE->getLeft());
		release(pSE->getRight());
	}

	delete expression;
}