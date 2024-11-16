#include <iostream>
#include "Control.h"
#include "Decorator.h"
#include "Beverage.h"
#include "BeverageDecorator.h"

int main() {
	Control* plistctrl = new ListControl();
	//plistctrl->draw();

	Decorator* plistctrl_b = new BorderDec(plistctrl);
	//plistctrl_b->draw();

	Decorator* plistctrl_b_v = new VerScrollBarDec(plistctrl_b);
	plistctrl_b_v->draw();

	std::cout << "=================================================" << std::endl;

	Control* plistctr2 = new ListControl();

	Decorator* plistctrl_h = new HorScrollBarDec(plistctr2);
	plistctrl_h->draw();

	std::cout << "=================================================" << std::endl;

	delete plistctrl_h;
	delete plistctr2;

	delete plistctrl_b_v;
	delete plistctrl_b;
	delete plistctrl;

	Beverage* pfruit = new FruitBeverage();
	BeverageDecorator* pfruit_add_bubb = new BubbleDec(pfruit);
	BeverageDecorator* pfruit_add_bubb_sugar = new SugarDec(pfruit_add_bubb);
	std::cout << "The price after adding bubble and sugar is: $" 
				<< pfruit_add_bubb_sugar->getprice() << " ." << std::endl;

	delete pfruit_add_bubb_sugar;
	delete pfruit_add_bubb;
	delete pfruit;

	return 0;
}