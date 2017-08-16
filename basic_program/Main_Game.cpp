#include <iostream>
#include "DxLib.h"
#include "Main_Game.h"


Main_Game::Main_Game()
{

}

void Main_Game::Main_Load()
{
	test_1.Load("pack/test/ui/test_button_box.png");
	test_2.Load("pack/test/ui/test_button_box_1.png");
}

void Main_Game::Main_Init()
{

}

void Main_Game::Main_Game_Loop()
{
	Main_Init();
	Main_Load();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		//test.BoxColliderMouse(50, 20, 50, 20, true);
		//test.CircleColliderMouse(50, 50, 50, true);

		test_1.BoxUI_Button(100, 100, 1.0f, 1.0f);
		test_2.BoxUI_Button(300, 100, 1.0f, 1.0f, MOUSE_INPUT_LEFT, true);

	}
}