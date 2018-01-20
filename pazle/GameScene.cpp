#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{
	game_scene_flag = 0;

	fade_out.init();

	level_switch.init();

	level01.init();
	level02.init();
	level03.init();

}

void GameScene::Load()
{
	level_switch.Load();

	fade_out.LoadGraphics();

	level01.Load();
	level02.Load();
	level03.Load();

}

void GameScene::DrawGameScene(int window_x, int window_y, Filer config, bool wire)
{
	SetBackgroundColor(50, 50, 50);
	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
		{
			DrawString(0, 0, "GameScene", GetColor(0, 0, 0));

			//レベル選択
			if (level_switch.select_level == 0)
			{
				level_switch.Draw(0, 0, wire);

				//各レベルのオブジェクトを初期化
				level01.init();
				level02.init();
				level03.init();

			}
			else if (level_switch.select_level == 1)//レベル1
			{
				level01.Draw(window_x / 2 - 50, window_y / 2 - 100, config, wire);
				level_switch.ResetButtonDraw(window_x - 100, window_y - 100, wire);//レベル選択に戻るボタン
			}
			else if (level_switch.select_level == 2)//レベル2
			{
				level02.Draw(window_x / 2 - 50, window_y / 2 - 100, config, wire);
				level_switch.ResetButtonDraw(window_x - 100, window_y - 100, wire);//レベル選択に戻るボタン
			}
			else if (level_switch.select_level == 3)//レベル3
			{
				level03.Draw(window_x / 2 - 50, window_y / 2 - 100, config, wire);
				level_switch.ResetButtonDraw(window_x - 100, window_y - 100, wire);//レベル選択に戻るボタン
			}
		}
	}
}