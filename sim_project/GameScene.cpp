#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{
	game_scene_flag = 0;

	fade_out.init();
	fade_in.init();

	CS.init();
}

void GameScene::Load()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();

	CS.Load();
}

void GameScene::DrawGameScene(int window_x, int window_y, Filer config, bool wire)
{
	//�ݒ�t�@�C���֘A��ǂݍ���
	config.FileOpen_Config();
	if (config.language_data.japanese_flag == 1)
	{
		config.FileOpen_Japanese();
	}
	else if (config.language_data.english_flag == 1)
	{
		config.FileOpen_English();
	}

	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//�t�F�[�h�A�E�g
		{
			//DrawString(0, 0, "GameScene", GetColor(0, 0, 0));

			CS.Draw(window_x, window_y, config, wire);

			//if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)//�t�F�[�h�C��(�Q�[����ʂ��甲����Ƃ��̏���)
			{

			}
		}
	}
}