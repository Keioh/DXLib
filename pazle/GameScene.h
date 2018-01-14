#pragma once
#include "DxLib.h"
#include "Level02.h"

class GameScene
{
private:

public:
	GameScene();

	int game_scene_flag;


	Level02 level01;

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, bool wire);

};