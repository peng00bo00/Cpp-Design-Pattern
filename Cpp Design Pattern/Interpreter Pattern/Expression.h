#pragma once
#include <string>
#include <map>

class Expression
{
public:
	Expression(int num, char sign) 
		: m_dbg_num(num), m_dbg_sign(sign) { }
	virtual ~Expression() { }

	virtual int interpret(std::map<char, int> var) = 0;

private:
	int m_dbg_num;
	char m_dbg_sign;
};

class VarExpression : public Expression
{
public:
	VarExpression(const char& key, int num, char sign)
		: Expression(num, sign), m_key(key) { }

	virtual int interpret(std::map<char, int> var) {
		return var[m_key];
	}

private:
	char m_key;
};

class SymbolExpression : public Expression
{
public:
	SymbolExpression(Expression *left, Expression *right, int num, char sign)
		: m_left(left), m_right(right), Expression(num, sign) { }

	Expression* getLeft() { return m_left; }
	Expression* getRight() { return m_right; }

protected:
	Expression* m_left;
	Expression* m_right;
};

class AddExpression : public SymbolExpression
{
public:
	AddExpression(Expression* left, Expression* right, int num, char sign)
		: SymbolExpression(left, right, num, sign) { }
	
	virtual int interpret(std::map<char, int> var) {
		int value1 = m_left->interpret(var);
		int value2 = m_right->interpret(var);
		int result = value1 + value2;

		return result;
	}
};

class SubExpression : public SymbolExpression
{
public:
	SubExpression(Expression* left, Expression* right, int num, char sign)
		: SymbolExpression(left, right, num, sign) {
	}

	virtual int interpret(std::map<char, int> var) {
		int value1 = m_left->interpret(var);
		int value2 = m_right->interpret(var);
		int result = value1 - value2;

		return result;
	}
};

Expression* analyse(std::string strExp);
void release(Expression* expression);