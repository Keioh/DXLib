#pragma once
#include "button_ui.h"

class Start
{
private:
	int hit_buffer;

	int anime_alph;

public:
	Start();

	ButtonUI start;

	void init();
	void LoadGraphics();

	int DrawStartButton(int x, int y, float speed, bool wire);
};