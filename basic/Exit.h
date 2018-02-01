#pragma once
#include "button_ui.h"
#include "FileInput.h"
#include "sound_system.h"

class Exit
{
private:
	int hit_buffer;

	int anime_alph;
	
public:
	Exit();

	ButtonUI exit;
	SoundSystem se_exit, se_exit_click;

	void init();
	void Load();

	void CollisionHit(Filer config);

	int DrawExitButton(int x, int y, float speed, Filer config, bool wire);
};