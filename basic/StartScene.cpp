#include "StartScene.h"

void StartScene::LoadGraphics()
{
	start.LoadGraphics();
	load.LoadGraphics();
	option.LoadGraphics();
	exit.LoadGraphics();
}

void StartScene::Init()
{
	start_scene_flag = 0;
	start.init();
	load.init();
	option.init();
	exit.init();
}

void StartScene::DrawStartScene(int window_x, int window_y, bool wire)
{
	while (start_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		//�j���[�Q�[���{�^��
		if (start.DrawStartButton(window_x / 2 - 500, window_y / 2, wire) == 1)
		{
			StartScene::Init();//���������Ă���
			start_scene_flag = 1;//���[�v�𔲂���
		}

		//���[�h�{�^��
		if (load.DrawLoadButton(window_x / 2 - 475, window_y / 2 + 55, wire) == 1)
		{
			StartScene::Init();//���������Ă���
			start_scene_flag = 2;//���[�v�𔲂���
		}

		//�I�v�V�����{�^��
		if (option.DrawOptionButton(window_x / 2 - 450, window_y / 2 + 110, wire) == 1)
		{
			StartScene::Init();//���������Ă���
			start_scene_flag = 3;//���[�v�𔲂���
		}

		//�I���{�^��
		if (exit.DrawExitButton(window_x / 2 - 425, window_y / 2 + 165, wire) == 1)
		{
			StartScene::Init();//���������Ă���
			start_scene_flag = -1;//���[�v�𔲂���
		}
	}
}