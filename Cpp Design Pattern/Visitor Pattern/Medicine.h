#pragma once
#include <string>
#include <iostream>


class Visitor;
class Visitor_SFRY;
class Visitor_QYRY;

class Medicine;
class M_asplcrp;
class M_fftdnhsp;
class M_dlx;

class Medicine
{
public:
	virtual ~Medicine() { }

	virtual void Accept(Visitor* pvisitor) = 0;
	virtual std::string getMdcName() = 0;
	virtual float getPrice() = 0;
};

class M_asplcrp : public Medicine
{
public:
	void Accept(Visitor* pvisitor);

	virtual std::string getMdcName() {
		return "阿司匹林";
	}

	virtual float getPrice() {
		return 46.8f;
	}
};

class M_fftdnhsp : public Medicine
{
public:
	void Accept(Visitor* pvisitor);

	virtual std::string getMdcName() {
		return "氟伐他汀钠";
	}

	virtual float getPrice() {
		return 111.3f;
	}
};

class M_dlx : public Medicine
{
public:
	void Accept(Visitor* pvisitor);
	
	virtual std::string getMdcName() {
		return "黛力新";
	}

	virtual float getPrice() {
		return 122.0f;
	}
};

class Visitor
{
public:
	virtual ~Visitor() {}
	virtual void Visit_aspl(M_asplcrp* pelem) = 0;
	virtual void Visit_fftdnhsp(M_fftdnhsp* pelem) = 0;
	virtual void Visit_dlx(M_dlx* pelem) = 0;
};

class Visitor_SFRY : public Visitor
{
public:
	virtual void Visit_aspl(M_asplcrp* pelem) {
		float tmpprice = pelem->getPrice();
		std::cout << "收费人员累计药品" << pelem->getMdcName() << "的价格: " << tmpprice << std::endl;
		m_totalcost += tmpprice;
	}

	virtual void Visit_fftdnhsp(M_fftdnhsp* pelem) {
		float tmpprice = pelem->getPrice();
		std::cout << "收费人员累计药品" << pelem->getMdcName() << "的价格: " << tmpprice << std::endl;
		m_totalcost += tmpprice;
	}

	virtual void Visit_dlx(M_dlx* pelem) {
		float tmpprice = pelem->getPrice();
		std::cout << "收费人员累计药品" << pelem->getMdcName() << "的价格: " << tmpprice << std::endl;
		m_totalcost += tmpprice;
	}

	float getTotalCost() {
		return m_totalcost;
	}

private:
	float m_totalcost = 0.0f;
};

class Visitor_QYRY : public Visitor
{
public:
	virtual void Visit_aspl(M_asplcrp* pelem) {
		std::cout << "取药人员将药品" << pelem->getMdcName() << "拿给了我" << std::endl;
	}

	virtual void Visit_fftdnhsp(M_fftdnhsp* pelem) {
		std::cout << "取药人员将药品" << pelem->getMdcName() << "拿给了我" << std::endl;
	}

	virtual void Visit_dlx(M_dlx* pelem) {
		std::cout << "取药人员将药品" << pelem->getMdcName() << "拿给了我" << std::endl;
	}
};