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
		return "��˾ƥ��";
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
		return "������͡��";
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
		return "������";
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
		std::cout << "�շ���Ա�ۼ�ҩƷ" << pelem->getMdcName() << "�ļ۸�: " << tmpprice << std::endl;
		m_totalcost += tmpprice;
	}

	virtual void Visit_fftdnhsp(M_fftdnhsp* pelem) {
		float tmpprice = pelem->getPrice();
		std::cout << "�շ���Ա�ۼ�ҩƷ" << pelem->getMdcName() << "�ļ۸�: " << tmpprice << std::endl;
		m_totalcost += tmpprice;
	}

	virtual void Visit_dlx(M_dlx* pelem) {
		float tmpprice = pelem->getPrice();
		std::cout << "�շ���Ա�ۼ�ҩƷ" << pelem->getMdcName() << "�ļ۸�: " << tmpprice << std::endl;
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
		std::cout << "ȡҩ��Ա��ҩƷ" << pelem->getMdcName() << "�ø�����" << std::endl;
	}

	virtual void Visit_fftdnhsp(M_fftdnhsp* pelem) {
		std::cout << "ȡҩ��Ա��ҩƷ" << pelem->getMdcName() << "�ø�����" << std::endl;
	}

	virtual void Visit_dlx(M_dlx* pelem) {
		std::cout << "ȡҩ��Ա��ҩƷ" << pelem->getMdcName() << "�ø�����" << std::endl;
	}
};