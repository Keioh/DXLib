#pragma once
#include "button_ui.h"

class Load
{
private:

public:
	Load();

	ButtonUI load;

	void init();
	void LoadGraphics();

	int DrawLoadButton(int x, int y, bool wire);

};