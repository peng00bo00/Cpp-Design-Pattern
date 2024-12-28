#pragma once
#include <iostream>

class WebAddr
{
public:
	virtual void visit() = 0;
	virtual ~WebAddr() { }
};

class WebAddr_Shopping : public WebAddr
{
public:
	void visit()
	{
		std::cout << "Visit Shopping website!" << std::endl;
	}
};

class WebAddr_Video : public WebAddr
{
public:
	void visit()
	{
		std::cout << "Visit Video website!" << std::endl;
	}
};

class WebAddrProxy : public WebAddr
{
public:
	WebAddrProxy(WebAddr* pwebaddr) : mp_webaddr(pwebaddr) { }

public:
	virtual void visit()
	{
		mp_webaddr->visit();
	}

private:
	WebAddr* mp_webaddr;
};