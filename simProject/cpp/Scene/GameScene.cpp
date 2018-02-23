#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{	
	game_scene_flag = 0;
	fps_counter.fps = 60;

	fade_out.init();
	fade_in.init();

	infomation_bar.Init();

	research.Init();
	study.Init();
	diplomacy.Init();

	CS.init();
	CN_MODE.Init();
	faction_tab.Init();

	building.Init();
	headquarters.Init();

	camera.Init();
	timer.Init();
}

void GameScene::Load()
{
	fade_out.LoadGraphics();
	fade_in.LoadGraphics();

	infomation_bar.Load();

	research.Load();
	study.Load();
	diplomacy.Load();

	CS.Load();
	CN_MODE.Load();
	timer.Load();
	faction_tab.Load();

	building.Load();
	headquarters.Load();

	terrain.Load("pack/GameObject/models/terrein.png");

	test_textur = LoadGraph("pack/GameObject/GameUI/time/years.png");
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

	terrain.Transform(VGet(1.0f, 1.0f, 1.0f), 90.0f, 0.0f, 0.0f, VGet(0.0f, 0.0f, 0.0f));//�RD��Ԃɉ摜��\��
	headquarters.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(0.0f, 0.1f, 0.0f));//�{���n�̈ʒu
	building.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(0.5f, 0.1f, 0.0f));

	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		fps_counter.Update();

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
				building.Draw(wire);

				faction_tab.Draw(0, 0, config, wire);//�L�����N�^���{�^��		
				DrawGraph(window_x - 256, 0, test_textur, TRUE);
				timer.Draw(window_x - 48, 128, wire);//���Ԃ�i�߂�{�^��
				research.Draw(window_x - (256 + 32), 24, wire);//�����{�^��
				study.Draw(window_x - (256 + 64), 24, wire);//�׋��{�^��
				diplomacy.Draw(window_x - (256 + 96), 24, wire);//�O���{�^��
				infomation_bar.Draw(window_x - (512 + 256), 0, wire);//���o�[
				money.Draw(window_x - (256 + 128), 8, wire);//�����̕\��

				CN_MODE.Draw(window_x / 2 - 128, 100, wire);

				camera.Set(window_x, window_y, VGet(0.0f, 2.0f, -1.0f), wire);//�J����

				fps_counter.Draw(10, 10);
			}
			else if (CS.character_number < 0)//�}�C�i�X�̒l������Ă�����O�ŏ������B
			{
				CS.character_number = 0;
			}


			//if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)//�t�F�[�h�C��(�Q�[����ʂ��甲����Ƃ��̏���)
			{

			}
		}
		fps_counter.Wait();
	}
}