#pragma once
#include "button_ui.h"

class Diplomacy
{
private:

public:
	ButtonUI diplomacy_button;

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);
};