#include "Main_Game.h"

Main_Game::Main_Game()
{
	Main_Game::Main_Init();
}

void Main_Game::Main_Load()
{
	config_data.FileOpen_Config();//設定ファイル読み込み
	config_data.FileOpen_Language();//言語ファイル読み込み
	main_system.size.x = config_data.window_data.windowX;//windowの大きさをmain_systemに代入
	main_system.size.y = config_data.window_data.windowY;
	main_system.size.bit = config_data.window_data.windowBit;
	main_system.fullscreen = config_data.window_data.fullscreen;
	SetGraphMode(main_system.size.x, main_system.size.y, main_system.size.bit);//設定ファイルで設定した大きさにwindowを変更

	Loading_scene.Load();//ローディング画像を読み込む
	Logo_scene.Load();//ロゴー画像を読み込む

	Start_scene.Load();//スタート画像を読み込む
	Game_scene.Load();//ゲーム画像を読み込む
	Load_scene.Load();//ロード画像を読み込む
}

void Main_Game::Main_Init()
{
	Loading_scene.Init();//ローディング画面初期化
	Logo_scene.init();//ロゴ画面初期化

	Start_scene.Init(config_data);//スタート画面初期化
	Game_scene.Init();//ゲーム画面初期化
	Load_scene.Init();//ロード画面を初期化
}

void Main_Game::Main_Game_Loop() 
{
	wire_flag = true;

	Main_Init();
	Main_Load();


	while (Start_scene.start_scene_flag != -1 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Loading_scene.DrawLoadingScene(main_system.size.x - 190, main_system.size.y - 60);//ロード画面(1番目に書く)
		Logo_scene.DrawLogoScene((main_system.size.x / 2) - 140, (main_system.size.y / 2) - 70, config_data);//ロゴ画面(2番目に書く)


		if (Start_scene.start_scene_flag == 0)//タイトル画面
		{
			Start_scene.DrawStartScene(main_system.size.x, main_system.size.y, config_data, wire_flag);//スタート画面
		}

		if (Start_scene.start_scene_flag == 1)//ゲーム画面へ
		{
			Game_scene.DrawGameScene(main_system.size.x, main_system.size.y, wire_flag);//ゲーム画面
			Start_scene.Init(config_data);//スタート画面初期化
			Game_scene.Init();//ゲーム画面初期化
			Load_scene.Init();//ロード画面を初期化
		}
	}
}