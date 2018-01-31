#pragma once
#include "switchObject.h"

class Level01
{
private:
	int rand_power;
	int anime_alph;
	int line_color[4];
	int timer;

	int line_anime;

	bool line_color_flag;

	Vector3 random_pos[4];

	int box_number[4];
	int triangle_number;

	void ClickEvent();
	void HitEvent();

public:

	SwitchObject object[4];

	bool clear_flag;//�X�e�[�W�N���A�t���O

	void init();
	void Load();
	bool Draw(int pos_x, int pos_y, Filer config, bool wire);

};