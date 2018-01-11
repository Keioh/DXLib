#pragma once
#include "Button_ui.h"

class OptionReturn
{
private:

public:
	OptionReturn();

	ButtonUI option_return;

	void init();
	void LoadGraphics();

	int DrawOtpionReturnButton(int x, int y, bool wire);

};