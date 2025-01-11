#pragma once
#include <string>

class Mediator;
class CtrlParent;


class Mediator
{
public:
	virtual ~Mediator() {}

	virtual void createCtrl() = 0;
	virtual void ctrlChanged(CtrlParent*) = 0;
};

class CtrlParent
{
public:
	CtrlParent(Mediator* ptmpm, std::string caption)
		: m_pmediator(ptmpm), m_caption(caption) {
	}

	virtual ~CtrlParent() {}

public:
	virtual void Changed() {
		m_pmediator->ctrlChanged(this);
	}

	virtual void Enable(bool sign) = 0;

protected:
	Mediator* m_pmediator;
	std::string m_caption;
};