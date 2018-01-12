#pragma once
#include "DxLib.h"
#include "Level01.h"

class GameScene
{
private:

public:
	GameScene();

	int game_scene_flag;


	Level01 level01;

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, bool wire);

};