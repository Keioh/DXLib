#pragma once
#include "button_ui.h"


class BGMMute
{
private:

public:
	BGMMute();

	ButtonUI bgm_mute;

	void init();
	void LoadGraphics();

	int DrawBGMMuteButton(int x, int y, bool wire);

};