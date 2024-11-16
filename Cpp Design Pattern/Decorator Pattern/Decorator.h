#pragma once
#include <iostream>
#include "Control.h"

class Decorator : public Control
{
public:
	Decorator(Control* tmpctrl)
		: m_control(tmpctrl){ }

	virtual void draw() {
		m_control->draw();
	}

private:
	Control* m_control;
};

class BorderDec : public Decorator
{
public:
	BorderDec(Control* tmpctrl) 
		: Decorator(tmpctrl) { }

	void draw() override {
		Decorator::draw();
		drawBorder();
	}

private:
	void drawBorder() {
		std::cout << "Drawing a border..." << std::endl;
	}
};

class VerScrollBarDec : public Decorator
{
public:
	VerScrollBarDec(Control* tmpctrl) 
		: Decorator(tmpctrl) { }

	void draw() override {
		Decorator::draw();
		drawVerScrollBar();
	}

private:
	void drawVerScrollBar() {
		std::cout << "Drawing a vertical scroll bar..." << std::endl;
	}
};

class HorScrollBarDec : public Decorator
{
public:
	HorScrollBarDec(Control* tmpctrl)
		: Decorator(tmpctrl) { }

	void draw() override {
		Decorator::draw();
		drawHorScrollBar();
	}

private:
	void drawHorScrollBar() {
		std::cout << "Drawing a horizontal scroll bar..." << std::endl;
	}
};