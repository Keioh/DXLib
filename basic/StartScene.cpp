#include "StartScene.h"

void StartScene::LoadGraphics()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();
	
	start.LoadGraphics();
	load.LoadGraphics();
	option.LoadGraphics();
	exit.LoadGraphics();
}

void StartScene::Init()
{
	start_scene_flag = 0;

	start_pos_x = -10;
	load_pos_x = -15;
	option_pos_x = -20;
	exit_pos_x = -25;
	anime_x = 1.0f;

	fade_out.init();
	fade_in.init();

	start.init();
	load.init();
	option.init();
	exit.init();
}

void StartScene::DrawStartScene(int window_x, int window_y, bool wire)
{
	while (start_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
		{

			//ニューゲームボタン
			if (start.DrawStartButton(125 + start_pos_x, window_y - 265, wire) == 1)
			{
				StartScene::Init();//初期化してから
				start_scene_flag = 1;//ループを抜ける
			}

			//ロードボタン
			if (load.DrawLoadButton(150 + load_pos_x, window_y - 210, wire) == 1)
			{
				StartScene::Init();//初期化してから
				start_scene_flag = 2;//ループを抜ける
			}

			//オプションボタン
			if (option.DrawOptionButton(175 + option_pos_x, window_y - 155, wire) == 1)
			{
				flag = 3;//フラグを３にする。
			}

			//終了ボタン
			if (exit.DrawExitButton(200 + exit_pos_x, window_y - 100, wire) == 1)
			{
				StartScene::Init();//初期化してから
				start_scene_flag = -1;//ループを抜ける
			}

			//オプション画面へ移動する際の処理
			if (flag == 3)
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
				{
					StartScene::Init();//初期化してから
					flag = 0;//フラグを０で初期化してから
					start_scene_flag = 3;//ループを抜ける
				}
			}

			//各ボタンのスライドアニメーション
			if (start_pos_x < 0)
			{
				start_pos_x += anime_x;
				if (start_pos_x >= 0)
				{
					start_pos_x = 0;
				}
			}

			if (load_pos_x < 0)
			{
				load_pos_x += anime_x;
				if (load_pos_x >= 0)
				{
					load_pos_x = 0;
				}
			}

			if (option_pos_x < 0)
			{
				option_pos_x += anime_x;
				if (option_pos_x >= 0)
				{
					option_pos_x = 0;
				}
			}

			if (exit_pos_x < 0)
			{
				exit_pos_x += anime_x;
				if (exit_pos_x >= 0)
				{
					exit_pos_x = 0;
				}
			}
		}
	}
}