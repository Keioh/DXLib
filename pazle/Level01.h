#pragma once
#include "switchObject.h"

class Level01
{
private:
	int rand_power;
	int line_color[4];

	void ClickEvent();
	void HitEvent();

public:

	SwitchObject object[4];

	void init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);

};