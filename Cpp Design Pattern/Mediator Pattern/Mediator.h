#pragma once
#include "Common.h"
#include "Ctrl.h"


class contrMediator : public Mediator
{
public:
	~contrMediator() {
		if (mp_login) { delete mp_login; mp_login = nullptr; }
		if (mp_logout) { delete mp_logout; mp_logout = nullptr; }

		if (mp_rbtn1) { delete mp_rbtn1; mp_rbtn1 = nullptr; }
		if (mp_rbtn2) { delete mp_rbtn2; mp_rbtn2 = nullptr; }

		if (mp_edtctl1) { delete mp_edtctl1; mp_edtctl1 = nullptr; }
		if (mp_edtctl2) { delete mp_edtctl2; mp_edtctl2 = nullptr; }
	}

	void createCtrl() {
		mp_login = new Button(this, "LogIn");
		mp_logout = new Button(this, "LogOut");

		mp_rbtn1 = new RadioBtn(this, "Visitor LogIn");
		mp_rbtn2 = new RadioBtn(this, "Visitor LogOut");

		mp_edtctl1 = new EditCtrl(this, "Account EditCtrl");
		mp_edtctl2 = new EditCtrl(this, "Password EditCtrl");

		// set initial state
		mp_rbtn1->Selected(true);
		mp_rbtn2->Selected(false);

		mp_edtctl1->Enable(false);
		mp_edtctl2->Enable(false);

		mp_login->Enable(true);
		mp_logout->Enable(false);
	}

	void ctrlChanged(CtrlParent *p_ctrl) {
		if (p_ctrl == mp_login) {
			std::cout << "Login to the game..." << std::endl;
		}
		else if (p_ctrl == mp_logout) {
			std::cout << "Log out. Good Bye!" << std::endl;
		}

		if (p_ctrl == mp_rbtn1) {
			mp_rbtn1->Selected(true);
			mp_rbtn2->Selected(false);

			mp_edtctl1->Enable(false);
			mp_edtctl2->Enable(false);

			mp_login->Enable(true);
		}
		else if (p_ctrl == mp_rbtn2) {
			mp_rbtn1->Selected(false);
			mp_rbtn2->Selected(true);

			mp_edtctl1->Enable(true);
			mp_edtctl2->Enable(true);

			if (mp_edtctl1->isContentEmpty() || mp_edtctl2->isContentEmpty()) {
				mp_login->Enable(false);
			}
			else {
				mp_login->Enable(true);
			}
		}

		if (p_ctrl == mp_edtctl1 || p_ctrl == mp_edtctl2) {
			if (mp_edtctl1->isContentEmpty() || mp_edtctl2->isContentEmpty()) {
				mp_login->Enable(false);
			}
			else {
				mp_login->Enable(true);
			}
		}
	}

public:
	Button* mp_login = nullptr;
	Button* mp_logout = nullptr;

	RadioBtn* mp_rbtn1 = nullptr;
	RadioBtn* mp_rbtn2 = nullptr;

	EditCtrl* mp_edtctl1 = nullptr;
	EditCtrl* mp_edtctl2 = nullptr;
};