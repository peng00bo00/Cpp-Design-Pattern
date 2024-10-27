#pragma once
#include <iostream>

class Body
{
public:
	virtual void getName() = 0;
	virtual ~Body() { }
};

class Cloth
{
public:
	virtual void getName() = 0;
	virtual ~Cloth() { }
};

class Shoes
{
public:
	virtual void getName() = 0;
	virtual ~Shoes() { }
};

//====================================================================================

class Doll
{
public:
	Doll(Body* body, Cloth* cloth, Shoes* shoes):
		body(body), cloth(cloth), shoes(shoes) { }

	void Assemble() {
		std::cout << "A Barbie Doll is assembled." << std::endl;
		body->getName();
		cloth->getName();
		shoes->getName();
	}

private:
	Body* body;
	Cloth* cloth;
	Shoes* shoes;
};

//====================================================================================

class China_Body : public Body
{
public:
	virtual void getName() {
		std::cout << "The Body is made in China." << std::endl;
	}
};

class China_Cloth : public Cloth
{
public:
	virtual void getName() {
		std::cout << "The Cloth is made in China." << std::endl;
	}
};

class China_Shoes : public Shoes
{
public:
	virtual void getName() {
		std::cout << "The Shoes are made in China." << std::endl;
	}
};

//====================================================================================

class Japan_Body : public Body
{
public:
	virtual void getName() {
		std::cout << "The Body is made in Japan." << std::endl;
	}
};

class Japan_Cloth : public Cloth
{
public:
	virtual void getName() {
		std::cout << "The Cloth is made in Japan." << std::endl;
	}
};

class Japan_Shoes : public Shoes
{
public:
	virtual void getName() {
		std::cout << "The Shoes are made in Japan." << std::endl;
	}
};

//====================================================================================

class America_Body : public Body
{
public:
	virtual void getName() {
		std::cout << "The Body is made in America." << std::endl;
	}
};

class America_Cloth : public Cloth
{
public:
	virtual void getName() {
		std::cout << "The Cloth is made in America." << std::endl;
	}
};

class America_Shoes : public Shoes
{
public:
	virtual void getName() {
		std::cout << "The Shoes are made in America." << std::endl;
	}
};