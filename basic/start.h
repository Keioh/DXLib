#pragma once
#include "button_ui.h"

class Start
{
private:

public:
	Start();

	ButtonUI start;

	void init();
	void LoadGraphics();

	int DrawStartButton(int x, int y, bool wire);
};