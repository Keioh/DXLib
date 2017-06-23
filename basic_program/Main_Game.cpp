#include <iostream>
#include "DxLib.h"
#include "Main_Game.h"


Main_Game::Main_Game()
{

}

void Main_Game::Main_Load()
{

}

void Main_Game::Main_Init()
{

}

void Main_Game::Main_Game_Loop()
{
	Main_Init();
	//Main_Load();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		main_collision.BoxCollider(10, 100, 10, 50, true);
	}
}