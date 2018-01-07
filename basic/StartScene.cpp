#include "StartScene.h"

StartScene::StartScene()
{
	flag = 0;
	//StartScene::Init();
}

void StartScene::Load()
{
	back_wall_graphics = LoadGraph("pack/UI/Title/back_wall.png");//背景画像をロード

	bgm.LoadSound("pack/GameObject/bgm/01.wav");

	option_scene.Load();

	fade_out.LoadGraphics();
	fade_in.LoadGraphics();
	
	start.LoadGraphics();
	load.LoadGraphics();
	option.LoadGraphics();
	exit.LoadGraphics();
}

void StartScene::Init(Filer config)
{
	option_scene.Init(config);

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

void StartScene::DrawStartScene(int window_x, int window_y, Filer config, bool wire)
{
	config.FileOpen_Config();//設定ファイルの読み込み
	option_scene.bgm_volume.bgm_volume_slider.wheel_volume_buffer = config.sound_data.bgm_volume;//設定ファイルの値を代入(BGM)
	option_scene.bgm_mute.bgm_mute.switch_flag = config.sound_data.bgm_mute;//設定ファイルの値を代入(BGM_MUTE)

	option_scene.se_volume.se_volume_slider.wheel_volume_buffer = config.sound_data.se_volume;//設定ファイルの値を代入(SE)
	option_scene.se_mute.se_mute.switch_flag = config.sound_data.se_mute;//設定ファイルの値を代入(SE_MUTE)


	while (start_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

		//設定値はconfigから必ずファイルから引っ張ってくる
		bgm.sound_volume = config.sound_data.bgm_volume;
		bgm.sound_volume *= -config.sound_data.bgm_mute;//ミュート値はマイナスを掛けてからじゃないと逆になる
		bgm.Play(1.0f, DX_PLAYTYPE_LOOP);

		DrawGraph(0, 0, back_wall_graphics, TRUE);//背景画像を表示

		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
		{

			//ニューゲームボタン
			if (start.DrawStartButton(125 + start_pos_x, window_y - 265, wire) == 1)
			{
				StartScene::Init(config);//初期化してから
				start_scene_flag = 1;//ループを抜ける
			}

			//ロードボタン
			if (load.DrawLoadButton(150 + load_pos_x, window_y - 210, wire) == 1)
			{
				flag = 2;//フラグを2にする。
			}

			//オプションボタン
			if (option.DrawOptionButton(175 + option_pos_x, window_y - 155, wire) == 1)
			{
				flag = 3;//フラグを3にする。
			}

			//終了ボタン
			if (exit.DrawExitButton(200 + exit_pos_x, window_y - 100, wire) == 1)
			{
				StartScene::Init(config);//初期化してから
				start_scene_flag = -1;//ループを抜ける
			}

			//ロード画面へ移動する際の処理
			if (flag == 2)
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
				{
					StartScene::Init(config);//初期化してから
					flag = 0;//フラグを０で初期化してから
					start_scene_flag = 2;//ループを抜ける
				}
			}

			//オプション画面へ移動する
			if (flag == 3)
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
				{
					if (option_scene.DrawOptionScene(window_x, window_y, config, wire) == true)
					{
						StartScene::Init(config);//初期化してから
						flag = 0;
					}
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