#pragma once
#include "button_ui.h"


class GameTimer
{
private:
	ButtonUI timer;
	int play_graphics, pause_graphics;

public:
	int play_type;//0‚ªˆêŽž’âŽ~

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);
};