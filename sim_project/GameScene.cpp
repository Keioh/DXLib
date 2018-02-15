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
	timer.Init();
}

void GameScene::Load()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();

	CS.Load();
	timer.Load();
	faction_tab.Load();
	headquarters.Load();

	terrain.Load("pack/GameObject/models/terrein.png");
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

	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描写

	camera.Init();//カメラを初期化

	terrain.Transform(VGet(10.0f, 5.0f, 0.0f), 90, 0, 0, VGet(0, 0, 0));//３D空間に画像を表示
	headquarters.Transform(VGet(0.1f, 0.1f, 0.1f), 0,0,0,VGet(0, 0.1,0));//本拠地の位置

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

				terrain.Draw();//3D空間に画像表示

				headquarters.Draw(800, 500,config, wire);//本拠地
				faction_tab.Draw(0, 0, config, wire);//キャラクタ情報ボタン		
				timer.Draw(window_x - 200, 100, wire);//時間を進めるボタン
				camera.Set(window_x, window_y, VGet(0.0f, 2.0f, -1.0f), wire);//カメラ

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