#include "Main_Game.h"

Main_Game::Main_Game()
{
	Main_Game::Main_Init();
}

void Main_Game::Main_Load()
{
	Loading_scene.LoadGraphics();//���[�f�B���O�摜��ǂݍ���
	Logo_scene.LoadGraphics();//���S�[�摜��ǂݍ���

	Start_scene.LoadGraphics();//�X�^�[�g�摜��ǂݍ���
	Game_scene.LoadGraphics();//�Q�[���摜��ǂݍ���
	Option_scene.LoadGraphics();//�I�v�V�����摜��ǂݍ���
	Load_scene.LoadGraphics();//���[�h�摜��ǂݍ���
}

void Main_Game::Main_Init()
{
	Loading_scene.Init();//���[�f�B���O��ʏ�����
	Logo_scene.init();//���S��ʏ�����

	Start_scene.Init();//�X�^�[�g��ʏ�����
	Game_scene.Init();//�Q�[����ʏ�����
	Option_scene.Init();//�I�v�V������ʏ�����
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
		Logo_scene.DrawLogoScene((main_system.size.x / 2) - 140, (main_system.size.y / 2) - 70);//���S���(2�Ԗڂɏ���)


		if (Start_scene.start_scene_flag == 0)//�^�C�g�����
		{
			Start_scene.DrawStartScene(main_system.size.x, main_system.size.y, wire_flag);//�X�^�[�g���
		}

		if (Start_scene.start_scene_flag == 1)//�Q�[����ʂ�
		{
			Game_scene.DrawGameScene(main_system.size.x, main_system.size.y, wire_flag);//�Q�[�����
			Start_scene.Init();//�X�^�[�g��ʏ�����
			Game_scene.Init();//�Q�[����ʏ�����
		}

		if (Start_scene.start_scene_flag == 2)//���[�h��ʂ�
		{
			Load_scene.DrawLoadScene(main_system.size.x, main_system.size.y, wire_flag);//���[�h���
			Start_scene.Init();//�X�^�[�g��ʏ�����
			Load_scene.Init();//���[�h��ʂ�������
		}

		if (Start_scene.start_scene_flag == 3)//�I�v�V������ʂ�
		{
			Option_scene.DrawOptionScene(main_system.size.x, main_system.size.y, wire_flag);//�I�v�V�������
			Start_scene.Init();//�X�^�[�g��ʏ�����
			Option_scene.Init();//�I�v�V������ʏ�����
		}
	}
}