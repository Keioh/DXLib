#pragma once
#include "button_ui.h"

class Exit
{
private:
	int hit_buffer;

	int anime_alph;
	
public:
	Exit();

	ButtonUI exit;

	void init();
	void LoadGraphics();

	int DrawExitButton(int x, int y, float speed, bool wire);
};