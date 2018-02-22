#pragma once
#include "button_ui.h"
#include "FileInput.h"
#include "sound_system.h"

class Start
{
private:
	int hit_buffer;

	int anime_alph;

public:
	Start();

	ButtonUI start;
	SoundSystem se_start, se_start_click;

	void init();
	void Load();

	void CollisionHit(Filer config);

	int DrawStartButton(int x, int y, float speed, Filer config, bool wire);
};