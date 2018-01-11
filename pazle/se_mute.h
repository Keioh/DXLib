#pragma once
#include "button_ui.h"


class SEMute
{
private:

public:
	SEMute();

	ButtonUI se_mute;

	void init();
	void LoadGraphics();

	int DrawSEMuteButton(int x, int y, bool wire);

};