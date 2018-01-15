#pragma once
#include "DxLib.h"
#include "Level03.h"

class GameScene
{
private:

public:
	GameScene();

	int game_scene_flag;


	Level03 level01;

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, Filer config, bool wire);

};