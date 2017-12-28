#include <iostream>
#include "DxLib.h"
#include "Main_Game.h"

void Main_Game::Main_Load()
{
	Loading_scene.LoadGraphics();//���[�f�B���O�摜��ǂݍ���
	Logo_scene.LoadGraphics();//���S�[�摜��ǂݍ���

	Start_scene.LoadGraphics();
	Game_scene.LoadGraphics();
}

void Main_Game::Main_Init()
{
	Loading_scene.Init();//���[�f�B���O��ʏ�����
	Logo_scene.init();//���S��ʏ�����

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
		Loading_scene.DrawLoadingScene(main_system.size.x - 190, main_system.size.y - 60);//���[�h���(1�Ԗڂɏ���)
		Logo_scene.DrawLogoScene((main_system.size.x / 2) - 140, (main_system.size.y / 2) - 70);//���S���(2�Ԗڂɏ���)

		Start_scene.DrawStartScene(main_system.size.x, main_system.size.y, wire_flag);//�X�^�[�g���

		if (Start_scene.start_scene_flag == 1)//�Q�[����ʂ�
		{
			Game_scene.DrawGameScene(main_system.size.x, main_system.size.y, wire_flag);//�Q�[�����
		}
	}
}