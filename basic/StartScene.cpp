#include "StartScene.h"

void StartScene::LoadGraphics()
{
	start.LoadGraphics();
	load.LoadGraphics();
	option.LoadGraphics();
	exit.LoadGraphics();
}

void StartScene::Init()
{
	start_scene_flag = 0;
	start.init();
	load.init();
	option.init();
	exit.init();
}

void StartScene::DrawStartScene(int window_x, int window_y, bool wire)
{
	while (start_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		//ニューゲームボタン
		if (start.DrawStartButton(window_x / 2 - 500, window_y / 2, wire) == 1)
		{
			StartScene::Init();//初期化してから
			start_scene_flag = 1;//ループを抜ける
		}

		//ロードボタン
		if (load.DrawLoadButton(window_x / 2 - 475, window_y / 2 + 55, wire) == 1)
		{
			StartScene::Init();//初期化してから
			start_scene_flag = 2;//ループを抜ける
		}

		//オプションボタン
		if (option.DrawOptionButton(window_x / 2 - 450, window_y / 2 + 110, wire) == 1)
		{
			StartScene::Init();//初期化してから
			start_scene_flag = 3;//ループを抜ける
		}

		//終了ボタン
		if (exit.DrawExitButton(window_x / 2 - 425, window_y / 2 + 165, wire) == 1)
		{
			StartScene::Init();//初期化してから
			start_scene_flag = -1;//ループを抜ける
		}
	}
}