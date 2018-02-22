#pragma once
#include "button_ui.h"

class ReturnButton
{
private:

public:
	ReturnButton();

	ButtonUI return_button;

	void init();
	void LoadGraphics();

	int DrawReturnButton(int x, int y, bool wire);
};