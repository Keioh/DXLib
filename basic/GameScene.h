#pragma once
#include "DxLib.h"

class GameScene
{
private:

public:
	int game_scene_flag;

	void Init();
	void LoadGraphics();

	void DrawGameScene(int window_x, int window_y, bool wire);

};