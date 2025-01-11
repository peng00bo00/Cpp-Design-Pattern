#pragma once
#include "Common.h"
#include <string>
#include <iostream>


class Button : public CtrlParent
{
public:
	Button(Mediator* ptmpm, std::string caption)
		: CtrlParent(ptmpm, caption) { }

	virtual void Enable(bool sign) {
		if (sign) {
			std::cout << "Button " << m_caption << " is turned on." << std::endl;
		}
		else {
			std::cout << "Button " << m_caption << " is turned off." << std::endl;
		}
	}
};

class RadioBtn : public CtrlParent
{
public:
	RadioBtn(Mediator* ptmpm, std::string caption)
		: CtrlParent(ptmpm, caption) {
	}

	virtual void Enable(bool sign) { }

	void Selected(bool sign) {
		if (sign) {
			std::cout << "Radio Button " << m_caption << " is selected." << std::endl;
		}
		else {
			std::cout << "Radio Button " << m_caption << " is deselected." << std::endl;
		}
	}
};

class EditCtrl : public CtrlParent
{
public:
	EditCtrl(Mediator* ptmpm, std::string caption)
		: CtrlParent(ptmpm, caption) { }

	virtual void Enable(bool sign) {
		if (sign) {
			std::cout << "Edit Ctrl " << m_caption << " is turned on." << std::endl;
		}
		else {
			std::cout << "Edit Ctrl " << m_caption << " is turned off." << std::endl;
		}
	}

	bool isContentEmpty() {
		return m_content.empty();
	}

private:
	std::string m_content = "";
};