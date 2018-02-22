#pragma once
#include "button_ui.h"
#include "FileInput.h"

class SEVolumeSlider
{
private:

public:
	SEVolumeSlider();

	ButtonUI se_volume_slider;

	float volumeF;
	int volume;

	void init();
	void LoadGraphics();

	float DrawSEVolumeSlider(int x, int y, unsigned int color, Filer data, bool wire);

};