#pragma once
#include "switchObject.h"

class Level01
{
private:
	int rand_power;
	int line_color[4];

	Vector3 random_pos[4];

	void ClickEvent();
	void HitEvent();

public:

	SwitchObject object[4];

	bool clear_flag;//ステージクリアフラグ

	void init();
	void Load();
	bool Draw(int pos_x, int pos_y, Filer config, bool wire);

};