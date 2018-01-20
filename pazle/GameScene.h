#pragma once
#include "DxLib.h"
#include "LevelSwitch.h"

#include "fade_in.h"
#include "fade_out.h"

#include "Level01.h"
#include "Level02.h"
#include "Level03.h"

class GameScene
{
private:

public:
	GameScene();

	int game_scene_flag;	

	FadeIn fade_in;
	FadeOut fade_out;

	LevelSwitch level_switch;
	Level01 level01;
	Level02 level02;
	Level03 level03;

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, Filer config, bool wire);

};