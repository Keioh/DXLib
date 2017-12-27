#include <iostream>
#include "DxLib.h"
#include "Main_Game.h"

void Main_Game::Main_Load()
{
	Loading_scene.LoadGraphics();//���[�f�B���O�摜��ǂݍ���
	Logo_scene.LoadGraphics();//���S�[�摜��ǂݍ���
}

void Main_Game::Main_Init()
{
	Loading_scene.Init();//���[�f�B���O��ʏ�����
	Logo_scene.init();//���S��ʏ�����
}

void Main_Game::Main_Game_Loop() 
{
	wire_flag = true;

	Main_Init();
	Main_Load();


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Loading_scene.DrawLoadingScene(main_system.size.x - 190, main_system.size.y - 60);//���[�h���(1�Ԗڂɏ���)
		Logo_scene.DrawLogoScene((main_system.size.x / 2) - 140, (main_system.size.y / 2) - 70);//���S���(2�Ԗڂɏ���)

	}
}