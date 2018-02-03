#pragma once
#include "button_ui.h"


class English
{
private:

public:
	English();

	ButtonUI english;

	void init();
	void LoadGraphics();

	int DrawEnglishButton(int x, int y, bool wire);

};