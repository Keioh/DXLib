#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{
	game_scene_flag = 0;
}

void GameScene::LoadGraphics()
{
}

void GameScene::DrawGameScene(int window_x, int window_y, bool wire)
{
	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawString(0, 0, "GameScene", GetColor(0, 0, 0));

	}
}