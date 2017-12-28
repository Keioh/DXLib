#include <iostream>
#include "DxLib.h"
#include "Main_Game.h"

void Main_Game::Main_Load()
{
	Loading_scene.LoadGraphics();//ローディング画像を読み込む
	Logo_scene.LoadGraphics();//ロゴー画像を読み込む

	Start_scene.LoadGraphics();
	Game_scene.LoadGraphics();
}

void Main_Game::Main_Init()
{
	Loading_scene.Init();//ローディング画面初期化
	Logo_scene.init();//ロゴ画面初期化

	Start_scene.Init();
	Game_scene.Init();
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

		Start_scene.DrawStartScene(main_system.size.x, main_system.size.y, wire_flag);//スタート画面

		if (Start_scene.start_scene_flag == 1)//ゲーム画面へ
		{
			Game_scene.DrawGameScene(main_system.size.x, main_system.size.y, wire_flag);//ゲーム画面
		}
	}
}