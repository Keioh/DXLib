#pragma once
#include "DxLib.h"
#include "LevelSwitch.h"

#include "Level01.h"
#include "Level02.h"
#include "Level03.h"

class GameScene
{
private:

public:
	GameScene();

	int game_scene_flag;	

	LevelSwitch level_switch;
	Level01 level01;
	Level02 level02;
	Level03 level03;

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, Filer config, bool wire);

};