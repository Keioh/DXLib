#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{	
	game_scene_flag = 0;
	fps_counter.fps = 60;

	fade_out.init();
	fade_in.init();

	infomation_bar.Init();

	research.Init();
	study.Init();
	diplomacy.Init();

	CS.init();
	CN_MODE.Init();
	faction_tab.Init();

	building.Init();
	headquarters.Init();

	camera.Init();
	timer.Init();
}

void GameScene::Load()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();

	infomation_bar.Load();

	research.Load();
	study.Load();
	diplomacy.Load();

	CS.Load();
	CN_MODE.Load();
	timer.Load();
	faction_tab.Load();

	building.Load();
	headquarters.Load();

	terrain.Load("pack/GameObject/models/terrein.png");

	test_textur = LoadGraph("pack/GameObject/GameUI/time/years.png");
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

	terrain.Transform(VGet(1.0f, 1.0f, 1.0f), 90.0f, 0.0f, 0.0f, VGet(0.0f, 0.0f, 0.0f));//３D空間に画像を表示
	headquarters.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(0.0f, 0.1f, 0.0f));//本拠地の位置
	building.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(0.5f, 0.1f, 0.0f));

	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		fps_counter.Update();

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
				building.Draw(wire);

				faction_tab.Draw(0, 0, config, wire);//キャラクタ情報ボタン		
				DrawGraph(window_x - 256, 0, test_textur, TRUE);
				timer.Draw(window_x - 48, 128, wire);//時間を進めるボタン
				research.Draw(window_x - (256 + 32), 24, wire);//研究ボタン
				study.Draw(window_x - (256 + 64), 24, wire);//勉強ボタン
				diplomacy.Draw(window_x - (256 + 96), 24, wire);//外交ボタン
				infomation_bar.Draw(window_x - (512 + 256), 0, wire);//情報バー
				money.Draw(window_x - (256 + 128), 8, wire);//お金の表示

				CN_MODE.Draw(window_x / 2 - 128, 100, wire);

				camera.Set(window_x, window_y, VGet(0.0f, 2.0f, -1.0f), wire);//カメラ

				fps_counter.Draw(10, 10);
			}
			else if (CS.character_number < 0)//マイナスの値を取っていたら０で初期化。
			{
				CS.character_number = 0;
			}


			//if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)//フェードイン(ゲーム画面から抜けるときの処理)
			{

			}
		}
		fps_counter.Wait();
	}
}