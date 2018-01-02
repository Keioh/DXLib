#pragma once
#include "DxLib.h"

class GameScene
{
private:

public:
	GameScene();

	int game_scene_flag;

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, bool wire);

};