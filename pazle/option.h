#pragma once
#include "button_ui.h"
#include "FileInput.h"
#include "sound_system.h"

class Option
{
private:
	//int click_flag;

	int hit_buffer;

	int anime_alph;

public:
	Option();

	ButtonUI option;
	SoundSystem se_option, se_option_click;

	void init();
	void Load();

	void CollisionHit(Filer config);

	int DrawOptionButton(int x, int y, float speed, Filer config, bool wire);
};