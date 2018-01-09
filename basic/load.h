#pragma once
#include "button_ui.h"

class Load
{
private:
	int hit_buffer;

	int anime_alph;

public:
	Load();

	ButtonUI load;

	void init();
	void LoadGraphics();

	int DrawLoadButton(int x, int y, float speed, bool wire);

};