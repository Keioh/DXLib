#pragma once
#include "DxLib.h"

class LoadScene
{
private:

public:
	LoadScene();

	int load_scene_flag;

	void LoadGraphics();
	void Init();

	void DrawLoadScene(int window_x, int window_y, bool wire);

};