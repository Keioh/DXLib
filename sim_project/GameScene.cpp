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
	faction_tab.Init();
	headquarters.Init();

	camera.Init();

}

void GameScene::Load()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();

	CS.Load();
	faction_tab.Load();
	headquarters.Load();

	box3D = MV1LoadModel("pack/GameObject/models/terrein.x");
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

	camera.Init();//カメラを初期化

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
				MV1SetPosition(box3D, VGet(0, 0, 1.0f));//モデルの位置

				MV1DrawModel(box3D);//モデルの描写

				camera.Set(window_x, window_y, VGet(0.0f, 5.0f, 0.0f), wire);//カメラ

				headquarters.Draw(800, 500, config, wire);//test
				faction_tab.Draw(120, 120, config, wire);//キャラクタ情報ボタン

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