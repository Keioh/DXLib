#pragma once
#include "button_ui.h"

class Exit
{
private:

public:
	Exit();

	ButtonUI exit;

	void init();
	void LoadGraphics();

	int DrawExitButton(int x, int y, bool wire);
};