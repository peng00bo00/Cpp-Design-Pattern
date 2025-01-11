#pragma once
#include <iostream>

class ImageOS
{
public:
	virtual void draw(char* pData, int iLen) = 0;
	virtual ~ImageOS() { }
};


class ImageOS_Windows : public ImageOS
{
public:
	virtual void draw(char* pData, int iLen)
	{
		std::cout << "Loading in Windows platform" << std::endl;
	}
};

class ImageOS_Linux : public ImageOS
{
public:
	virtual void draw(char* pData, int iLen)
	{
		std::cout << "Loading in Linux platform" << std::endl;
	}
};

class ImageOS_Mac : public ImageOS
{
public:
	virtual void draw(char* pData, int iLen)
	{
		std::cout << "Loading in Mac platform" << std::endl;
	}
};