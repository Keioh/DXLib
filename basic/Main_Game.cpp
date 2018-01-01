#include "Main_Game.h"

Main_Game::Main_Game()
{
	Main_Game::Main_Init();
}

void Main_Game::Main_Load()
{
	Loading_scene.LoadGraphics();//ローディング画像を読み込む
	Logo_scene.LoadGraphics();//ロゴー画像を読み込む

	Start_scene.LoadGraphics();//スタート画像を読み込む
	Game_scene.LoadGraphics();//ゲーム画像を読み込む
	Option_scene.LoadGraphics();//オプション画像を読み込む
	Load_scene.LoadGraphics();//ロード画像を読み込む
}

void Main_Game::Main_Init()
{
	Loading_scene.Init();//ローディング画面初期化
	Logo_scene.init();//ロゴ画面初期化

	Start_scene.Init();//スタート画面初期化
	Game_scene.Init();//ゲーム画面初期化
	Option_scene.Init();//オプション画面初期化
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
		Logo_scene.DrawLogoScene((main_system.size.x / 2) - 140, (main_system.size.y / 2) - 70);//ロゴ画面(2番目に書く)


		if (Start_scene.start_scene_flag == 0)//タイトル画面
		{
			Start_scene.DrawStartScene(main_system.size.x, main_system.size.y, wire_flag);//スタート画面
		}

		if (Start_scene.start_scene_flag == 1)//ゲーム画面へ
		{
			Game_scene.DrawGameScene(main_system.size.x, main_system.size.y, wire_flag);//ゲーム画面
			Start_scene.Init();//スタート画面初期化
			Game_scene.Init();//ゲーム画面初期化
		}

		if (Start_scene.start_scene_flag == 2)//ロード画面へ
		{
			Load_scene.DrawLoadScene(main_system.size.x, main_system.size.y, wire_flag);//ロード画面
			Start_scene.Init();//スタート画面初期化
			Load_scene.Init();//ロード画面を初期化
		}

		if (Start_scene.start_scene_flag == 3)//オプション画面へ
		{
			Option_scene.DrawOptionScene(main_system.size.x, main_system.size.y, wire_flag);//オプション画面
			Start_scene.Init();//スタート画面初期化
			Option_scene.Init();//オプション画面初期化
		}
	}
}