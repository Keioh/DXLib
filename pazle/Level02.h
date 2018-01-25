#pragma once
#include "switchObject.h"

class Level02
{
private:
	int rand_power;
	int line_color[7];

	Vector3 random_pos[7];

	void ClickEvent();
	void HitEvent();


public:

	SwitchObject object[7];

	bool clear_flag;

	void init();
	void Load();
	bool Draw(int pos_x, int pos_y, Filer config, bool wire);

};