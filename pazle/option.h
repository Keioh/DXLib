#pragma once
#include "button_ui.h"

class Option
{
private:
	int click_flag;

	int hit_buffer;

	int anime_alph;

public:
	Option();

	ButtonUI option;

	void init();
	void LoadGraphics();

	int DrawOptionButton(int x, int y, float speed, bool wire);
};