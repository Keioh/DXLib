#pragma once
#include "FileInput.h"
#include "button_ui.h"
#include "sound_system.h"

class SwitchObject
{
private:
	SoundSystem hit_se, click_se;

	float r_buffer, click_r;

	int red;
	int blue;
	int green;

	float r;

public:
	ButtonUI switch_object;

	Vector3 rand_pos, pos;

	int object_switch_flag;

	void init();

	void Load();

	void Draw(int pos_x, int pos_y, Filer config, bool wire);

};