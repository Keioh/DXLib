#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{
	game_scene_flag = 0;

	fade_out.init();

	level_switch.init();

	level01.init();
	level02.init();
	level03.init();

}

void GameScene::Load()
{
	level_switch.Load();

	fade_out.LoadGraphics();

	level01.Load();
	level02.Load();
	level03.Load();

}

//�R���t�B�O�f�[�^�ǂݍ���
void GameScene::Config()
{
	config.FileOpen_Config();

}

void GameScene::DrawGameScene(int window_x, int window_y,  bool wire)
{
	SetBackgroundColor(50, 50, 50);
	GameScene::Config();
	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//�t�F�[�h�A�E�g
		{
			DrawString(0, 0, "GameScene", GetColor(0, 0, 0));

			//���x���I��
			if (level_switch.select_level == 0)
			{
				level_switch.Draw(0, 0, config, wire);

				//�e���x���̃I�u�W�F�N�g��������
				level01.init();
				level02.init();
				level03.init();

			}
			else if (level_switch.select_level == 1)//���x��1
			{
				if (level01.Draw(window_x / 2 - 50, window_y / 2 - 100, config, wire) == true)
				{
					level01.init();
					level_switch.select_level = 2;//level01���N���A�ł�����select_level��2�ɂ���
				}
				level_switch.ResetButtonDraw(window_x - 100, window_y - 100, wire);//���x���I���ɖ߂�{�^��
			}
			else if (level_switch.select_level == 2)//���x��2
			{
				if (level02.Draw(window_x / 2 - 50, window_y / 2 - 100, config, wire) == true)
				{
					level02.init();
					level_switch.select_level = 3;//level02���N���A�ł�����select_level��3�ɂ���
				}
				level_switch.ResetButtonDraw(window_x - 100, window_y - 100, wire);//���x���I���ɖ߂�{�^��
			}
			else if (level_switch.select_level == 3)//���x��3
			{
				level03.Draw(window_x / 2 - 50, window_y / 2 - 100, config, wire);
				level_switch.ResetButtonDraw(window_x - 100, window_y - 100, wire);//���x���I���ɖ߂�{�^��
			}
		}
	}
}