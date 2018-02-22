#pragma once
#include "button_ui.h"


class Japanese
{
private:

public:
	Japanese();

	ButtonUI japanese;

	void init();
	void LoadGraphics();

	int DrawJapaneseButton(int x, int y, bool wire);

};