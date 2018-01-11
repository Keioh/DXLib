#include "Main_Game.h"

Main_Game::Main_Game()
{
	Main_Game::Main_Init();
}

void Main_Game::Main_Load()
{
	config_data.FileOpen_Config();//�ݒ�t�@�C���ǂݍ���
	config_data.FileOpen_Language();//����t�@�C���ǂݍ���
	main_system.size.x = config_data.window_data.windowX;//window�̑傫����main_system�ɑ��
	main_system.size.y = config_data.window_data.windowY;
	main_system.size.bit = config_data.window_data.windowBit;
	main_system.fullscreen = config_data.window_data.fullscreen;
	SetGraphMode(main_system.size.x, main_system.size.y, main_system.size.bit);//�ݒ�t�@�C���Őݒ肵���傫����window��ύX

	Loading_scene.Load();//���[�f�B���O�摜��ǂݍ���
	Logo_scene.Load();//���S�[�摜��ǂݍ���

	Start_scene.Load();//�X�^�[�g�摜��ǂݍ���
	Game_scene.Load();//�Q�[���摜��ǂݍ���
	Load_scene.Load();//���[�h�摜��ǂݍ���
}

void Main_Game::Main_Init()
{
	Loading_scene.Init();//���[�f�B���O��ʏ�����
	Logo_scene.init();//���S��ʏ�����

	Start_scene.Init(config_data);//�X�^�[�g��ʏ�����
	Game_scene.Init();//�Q�[����ʏ�����
	Load_scene.Init();//���[�h��ʂ�������
}

void Main_Game::Main_Game_Loop() 
{
	wire_flag = true;

	Main_Init();
	Main_Load();


	while (Start_scene.start_scene_flag != -1 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Loading_scene.DrawLoadingScene(main_system.size.x - 190, main_system.size.y - 60);//���[�h���(1�Ԗڂɏ���)
		Logo_scene.DrawLogoScene((main_system.size.x / 2) - 140, (main_system.size.y / 2) - 70, config_data);//���S���(2�Ԗڂɏ���)


		if (Start_scene.start_scene_flag == 0)//�^�C�g�����
		{
			Start_scene.DrawStartScene(main_system.size.x, main_system.size.y, config_data, wire_flag);//�X�^�[�g���
		}

		if (Start_scene.start_scene_flag == 1)//�Q�[����ʂ�
		{
			Game_scene.DrawGameScene(main_system.size.x, main_system.size.y, wire_flag);//�Q�[�����
			Start_scene.Init(config_data);//�X�^�[�g��ʏ�����
			Game_scene.Init();//�Q�[����ʏ�����
			Load_scene.Init();//���[�h��ʂ�������
		}
	}
}