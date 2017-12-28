#pragma once
#include "DxLib.h"

class OptionScene
{
private:

public:

	int option_scene_flag;

	void LoadGraphics();
	void Init();

	void DrawOptionScene(int window_x, int window_y, bool wire);

};