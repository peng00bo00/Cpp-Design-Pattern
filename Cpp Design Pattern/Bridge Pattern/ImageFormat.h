#pragma once
#include "ImageOs.h"
#include <iostream>

class ImageFormat
{
public:
	ImageFormat(ImageOS* pimgos) : m_pImgOS(pimgos) { }
	virtual void parsefile(const char* pfilename) = 0;

protected:
	ImageOS* m_pImgOS;
};

class Image_png : public ImageFormat
{
public:
	Image_png(ImageOS* pimgos) : ImageFormat(pimgos) { }

	virtual void parsefile(const char* pfilename) {
		std::cout << "Loading .png file to pData..." << std::endl;

		int iLen = 100;
		char* pData = new char[iLen];

		m_pImgOS->draw(pData, iLen);

		delete pData;
	}
};

class Image_jpg : public ImageFormat
{
public:
	Image_jpg(ImageOS* pimgos) : ImageFormat(pimgos) {}

	virtual void parsefile(const char* pfilename) {
		std::cout << "Loading .jpg file to pData..." << std::endl;

		int iLen = 100;
		char* pData = new char[iLen];

		m_pImgOS->draw(pData, iLen);

		delete pData;
	}
};

class Image_bmp : public ImageFormat
{
public:
	Image_bmp(ImageOS* pimgos) : ImageFormat(pimgos) {}

	virtual void parsefile(const char* pfilename) {
		std::cout << "Loading .bmp file to pData..." << std::endl;

		int iLen = 100;
		char* pData = new char[iLen];

		m_pImgOS->draw(pData, iLen);

		delete pData;
	}
};