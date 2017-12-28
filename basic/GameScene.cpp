#include "GameScene.h"

void GameScene::Init()
{
	game_scene_flag = 0;

}

void GameScene::LoadGraphics()
{
	test_graphics = LoadGraph("pack/test/test.png");
}

void GameScene::DrawGameScene(int window_x, int window_y, bool wire)
{
	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawGraph(window_x/2 - 1280/2, window_y/2 - 720/2, test_graphics, TRUE);
	}
}