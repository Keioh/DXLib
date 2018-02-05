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

	CS.init();
}

void GameScene::Load()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();

	CS.Load();
}

void GameScene::DrawGameScene(int window_x, int window_y, Filer config, bool wire)
{
	//設定ファイル関連を読み込む
	config.FileOpen_Config();
	if (config.language_data.japanese_flag == 1)
	{
		config.FileOpen_Japanese();
	}
	else if (config.language_data.english_flag == 1)
	{
		config.FileOpen_English();
	}

	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
		{
			//DrawString(0, 0, "GameScene", GetColor(0, 0, 0));


			if (CS.character_number == 0)//キャラクタが選択されていなければ
			{
				CS.Draw(window_x, window_y, config, wire);
			}
			else if (CS.character_number > 0)//キャラクタが選択されていたら
			{
				camera.Set(VGet(config.window_data.windowX, config.window_data.windowY, 0.0f));
				DrawSphere3D(VGet(0.f, 0.f, 0.f), 250.f, 128, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);

			}
			else if (CS.character_number < 0)//マイナスの値を取っていたら０で初期化。
			{
				CS.character_number = 0;
			}


			//if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)//フェードイン(ゲーム画面から抜けるときの処理)
			{

			}
		}
	}
}