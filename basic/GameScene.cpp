#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{
	game_scene_flag = 0;

	fade_out.init();
	fade_in.init();

}

void GameScene::Load()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();

}

//コンフィグデータ読み込み
void GameScene::Config()
{
	config.FileOpen_Config();
}

void GameScene::DrawGameScene(int window_x, int window_y,  bool wire)
{
	SetBackgroundColor(50, 50, 50);
	GameScene::Config();
	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
		{
			DrawString(0, 0, "GameScene", GetColor(0, 0, 0));

			//if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)//フェードイン(ゲーム画面から抜けるときの処理)
			{

			}
		}
	}
}