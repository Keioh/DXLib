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

	void init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);

};