#pragma once
#include "button_ui.h"
#include "FileInput.h"

class BGMVolumeSlider
{
private:

public:
	BGMVolumeSlider();

	ButtonUI bgm_volume_slider;

	float volumeF;
	int volume;

	void init();
	void LoadGraphics();

	float DrawBGMVolumeSlider(int x, int y, unsigned int color, Filer data, bool wire);

};