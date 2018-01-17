#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{
	game_scene_flag = 0;


	level01.init();
}

void GameScene::Load()
{
	level01.Load();
}

void GameScene::DrawGameScene(int window_x, int window_y, Filer config, bool wire)
{
	SetBackgroundColor(50, 50, 50);
	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawString(0, 0, "GameScene", GetColor(0, 0, 0));
		level01.Draw(window_x / 2 - 50, window_y / 2 - 100, config, wire);

	}
}