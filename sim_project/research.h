#pragma once
#include "button_ui.h"

class Research
{
private:

public:
	ButtonUI research_button;

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);
};