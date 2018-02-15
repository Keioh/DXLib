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
	faction_tab.Init();
	headquarters.Init();

	camera.Init();
	timer.Init();
}

void GameScene::Load()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();

	CS.Load();
	timer.Load();
	faction_tab.Load();
	headquarters.Load();

	terrain.Load("pack/GameObject/models/terrein.png");
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

	SetDrawScreen(DX_SCREEN_BACK);//����ʂɕ`��

	camera.Init();//�J������������

	terrain.Transform(VGet(10.0f, 5.0f, 0.0f), 90, 0, 0, VGet(0, 0, 0));//�RD��Ԃɉ摜��\��
	headquarters.Transform(VGet(0.1f, 0.1f, 0.1f), 0,0,0,VGet(0, 0.1,0));//�{���n�̈ʒu

	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//�t�F�[�h�A�E�g
		{
			//DrawString(0, 0, "GameScene", GetColor(0, 0, 0));

			if (CS.character_number == 0)//�L�����N�^���I������Ă��Ȃ����
			{
				CS.Draw(window_x, window_y, config, wire);
			}
			else if (CS.character_number > 0)//�L�����N�^���I������Ă�����
			{			

				terrain.Draw();//3D��Ԃɉ摜�\��

				headquarters.Draw(800, 500,config, wire);//�{���n
				faction_tab.Draw(0, 0, config, wire);//�L�����N�^���{�^��		
				timer.Draw(window_x - 200, 100, wire);//���Ԃ�i�߂�{�^��
				camera.Set(window_x, window_y, VGet(0.0f, 2.0f, -1.0f), wire);//�J����

			}
			else if (CS.character_number < 0)//�}�C�i�X�̒l������Ă�����O�ŏ������B
			{
				CS.character_number = 0;
			}


			//if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)//�t�F�[�h�C��(�Q�[����ʂ��甲����Ƃ��̏���)
			{

			}
		}
	}
}