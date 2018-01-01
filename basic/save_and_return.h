#pragma once
#include "Button_ui.h"

class SaveAndReturn
{
private:

public:
	SaveAndReturn();

	ButtonUI save_and_return;

	void init();
	void LoadGraphics();

	int DrawSaveAndReturnButton(int x, int y, bool wire);

};