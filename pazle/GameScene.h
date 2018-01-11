#pragma once
#include "DxLib.h"
#include "switchObject.h"

class GameScene
{
private:

public:
	GameScene();

	int game_scene_flag;


	SwitchObject object[4];

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, bool wire);

};