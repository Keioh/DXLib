#pragma once
#include "button_ui.h"

class Option
{
private:

public:
	Option();

	ButtonUI option;

	void init();
	void LoadGraphics();

	int DrawOptionButton(int x, int y, bool wire);
};