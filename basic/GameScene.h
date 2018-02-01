#pragma once
#include "DxLib.h"
#include "FileInput.h"

#include "fade_in.h"
#include "fade_out.h"

class GameScene
{
private:
	Filer config;

public:
	GameScene();

	int game_scene_flag;	

	FadeIn fade_in;
	FadeOut fade_out;

	void Init();
	void Load();

	void Config();

	void DrawGameScene(int window_x, int window_y, bool wire);

};