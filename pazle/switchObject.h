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
	bool white_light;

	bool red_color_flag;
	bool green_color_flag;
	bool blue_color_flag;

	float r_buffer, click_r;
	float alph_double;

	int red;
	int blue;
	int green;

	int draw_alph;

	int light_grahics_blue, light_grahics_green	,light_grahics_orange, light_grahics_purple;
	int light_white;
	
	int light_grahics_blue_alph, light_grahics_green_alph, light_grahics_orange_alph, light_grahics_purple_alph;
	int light_white_alph;

	float r;

public:
	ButtonUI switch_object;

	Vector3 rand_pos, pos;

	int object_switch_flag;

	void init();
	void SoundReset();

	void Load();

	void Draw(int pos_x, int pos_y, Filer config, bool wire);

};