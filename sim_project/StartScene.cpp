#include "StartScene.h"

StartScene::StartScene()
{
	flag = 0;
	//StartScene::Init();
}

void StartScene::Load()
{
	back_wall_graphics = LoadGraph("pack/UI/Title/back_wall.png");//背景画像をロード
	info_graphics = LoadGraph("pack/UI/Title/info.png");//背景画像をロード

	//SEとBGMをロード
	bgm.LoadSound("pack/GameObject/bgm/01.wav");

	option_scene.Load();

	fade_out.LoadGraphics();
	fade_in.LoadGraphics();
	
	start.Load();
	load.LoadData();
	option.Load();
	exit.Load();
}

void StartScene::Init(Filer config)
{
	option_scene.Init(config);

	flag = 0;
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

void StartScene::SoundStop()//音を停止
{
	bgm.Stop();
}

void StartScene::OptionSeceneConfig(Filer config)//オプション画面のコンフィグ処理まとめ
{
	option_scene.bgm_volume.bgm_volume_slider.wheel_volume_buffer = config.sound_data.bgm_volume;//設定ファイルの値を代入(BGM)
	option_scene.bgm_mute.bgm_mute.switch_flag = config.sound_data.bgm_mute;//設定ファイルの値を代入(BGM_MUTE)

	option_scene.se_volume.se_volume_slider.wheel_volume_buffer = config.sound_data.se_volume;//設定ファイルの値を代入(SE)
	option_scene.se_mute.se_mute.switch_flag = config.sound_data.se_mute;//設定ファイルの値を代入(SE_MUTE)

	option_scene.japanese.japanese.switch_flag = config.language_data.japanese_flag;//設定ファイルの値を代入(JAPANESE)
	option_scene.english.english.switch_flag = config.language_data.english_flag;//設定ファイルの値を代入(ENGLISH)
}

void StartScene::DrawStartScene(int window_x, int window_y, Filer config, bool wire)
{
	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描写

	config.FileOpen_Config();//設定ファイルの読み込み
	StartScene::OptionSeceneConfig(config);//設定

	while (start_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{

		//設定値はconfigから必ずファイルから引っ張ってくる
		//ミュート値はマイナスを掛けてからじゃないと逆になる
		bgm.Play(config.sound_data.bgm_volume * -config.sound_data.bgm_mute, DX_PLAYTYPE_LOOP);//BGM再生

		DrawGraph(0, 0, back_wall_graphics, TRUE);//背景画像を表示
		DrawGraph(0, window_y - 32, info_graphics, TRUE);//背景画像を表示

		//ボックスコライダーにヒットしたときの処理
		//new gameの説明
		if (start.start.box_collision.hit == true)
		{
			DrawFormatString(10, window_y - 24, GetColor(255, 255, 255), "%s", config.string_data.start_info_new_game);
		}

		//loadの説明
		if (load.load.box_collision.hit == true)
		{
			DrawFormatString(10, window_y - 24, GetColor(255, 255, 255), "%s", config.string_data.start_info_load);
		}

		//optionの説明
		if (option.option.box_collision.hit == true)
		{
			DrawFormatString(10, window_y - 24, GetColor(255, 255, 255), "%s", config.string_data.start_info_option);
		}

		//exitの説明
		if (exit.exit.box_collision.hit == true)
		{
			DrawFormatString(10, window_y - 24, GetColor(255, 255, 255), "%s", config.string_data.start_info_exit);
		}

		//DrawFormatString(0, 0, GetColor(255, 255, 255), "flag = %d", flag);


		if (flag == 0)//フラグが0のとき、タイトル画面を表示
		{
			if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
			{
				//ニューゲームボタン
				if (start.DrawStartButton(125 + start_pos_x, window_y - 265, 10.0f, config, wire) == 1)
				{
					StartScene::Init(config);//初期化してから
					start_scene_flag = 1;//ループを抜ける
				}

				//ロードボタン
				if (load.DrawLoadButton(150 + load_pos_x, window_y - 210, 10.0f, config, wire) == 1)
				{
					flag = 2;//フラグを2にする。
				}

				//オプションボタン
				if (option.DrawOptionButton(175 + option_pos_x, window_y - 155, 10.0f, config, wire) == 1)
				{		
					flag = 3;//フラグを3にする。
				}

				//終了ボタン
				if (exit.DrawExitButton(200 + exit_pos_x, window_y - 100, 10.0f, config, wire) == 1)
				{
					StartScene::Init(config);//初期化してから
					start_scene_flag = -1;//ループを抜ける
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

		//フラグが2のとき、ロード画面へ移動する
		if (flag == 2)
		{
			if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
			{
				StartScene::Init(config);//初期化してから
				flag = 0;//フラグを０で初期化してから
			}
		}

		//フラグが3のとき、オプション画面へ移動する
		if (flag == 3)
		{
			if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
			{
				if (option_scene.DrawOptionScene(window_x, window_y, config, wire) == true)//ブラックアウトしたら
				{
					StartScene::Init(config);//初期化してから
					flag = 0;
				}
			}
		}
	}
}