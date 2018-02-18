#pragma once
#include "button_ui.h"

class Study
{
private:

public:
	ButtonUI study_button;

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);

};