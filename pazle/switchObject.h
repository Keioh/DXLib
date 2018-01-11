#pragma once
#include "button_ui.h"

class SwitchObject
{
private:

public:
	ButtonUI switch_object;

	int object_switch_flag;

	void init();

	void Load();

	void Draw(int pos_x, int pos_y, bool wire);

};