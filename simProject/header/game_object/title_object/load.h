#pragma once
#include "button_ui.h"
#include "FileInput.h"
#include "sound_system.h"

class Load
{
private:
	int hit_buffer;

	int anime_alph;

public:
	Load();

	ButtonUI load;	
	SoundSystem se_load, se_load_click;


	void init();
	void LoadData();

	void CollisionHit(Filer config);

	int DrawLoadButton(int x, int y, float speed, Filer config, bool wire);

};