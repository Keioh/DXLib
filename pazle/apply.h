#pragma once
#include "button_ui.h"


class Apply
{
private:

public:
	Apply();

	ButtonUI apply;

	void init();
	void LoadGraphics();

	int DrawApplyButton(int x, int y, bool wire);

};