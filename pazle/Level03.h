#pragma once
#include "switchObject.h"

class Level03
{
private:
	int rand_power;
	int line_color[9];

	Vector3 random_pos[9];

	void ClickEvent();
	void HitEvent();


public:

	SwitchObject object[9];

	void init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);

};