#pragma once
#include "FileInput.h"
#include "button_ui.h"
#include "sound_system.h"

class SwitchObject
{
private:
	SoundSystem hit_se, click_se;

	bool blue_light;
	bool green_light;
	bool orange_light;
	bool purple_light;

	float r_buffer, click_r;

	int red;
	int blue;
	int green;

	int light_grahics_blue, light_grahics_green	,light_grahics_orange, light_grahics_purple;
	
	int light_grahics_blue_alph, light_grahics_green_alph, light_grahics_orange_alph, light_grahics_purple_alph;

	float r;

public:
	ButtonUI switch_object;

	Vector3 rand_pos, pos;

	int object_switch_flag;

	void init();

	void Load();

	void Draw(int pos_x, int pos_y, Filer config, bool wire);

};