#include "StartScene.h"

StartScene::StartScene()
{
	flag = 0;
	//StartScene::Init();
}

void StartScene::Load()
{
	back_wall_graphics = LoadGraph("pack/UI/Title/back_wall.png");//�w�i�摜�����[�h

	bgm.LoadSound("pack/GameObject/bgm/01.wav");

	option_scene.Load();

	fade_out.LoadGraphics();
	fade_in.LoadGraphics();
	
	start.LoadGraphics();
	load.LoadGraphics();
	option.LoadGraphics();
	exit.LoadGraphics();
}

void StartScene::Init(Filer config)
{
	option_scene.Init(config);

	start_scene_flag = 0;

	start_pos_x = -10;
	load_pos_x = -15;
	option_pos_x = -20;
	exit_pos_x = -25;
	anime_x = 1.0f;

	fade_out.init();
	fade_in.init();

	start.init();
	load.init();
	option.init();
	exit.init();
}

void StartScene::DrawStartScene(int window_x, int window_y, Filer config, bool wire)
{
	config.FileOpen_Config();//�ݒ�t�@�C���̓ǂݍ���
	option_scene.bgm_volume.bgm_volume_slider.wheel_volume_buffer = config.sound_data.bgm_volume;//�ݒ�t�@�C���̒l����(BGM)
	option_scene.bgm_mute.bgm_mute.switch_flag = config.sound_data.bgm_mute;//�ݒ�t�@�C���̒l����(BGM_MUTE)

	option_scene.se_volume.se_volume_slider.wheel_volume_buffer = config.sound_data.se_volume;//�ݒ�t�@�C���̒l����(SE)
	option_scene.se_mute.se_mute.switch_flag = config.sound_data.se_mute;//�ݒ�t�@�C���̒l����(SE_MUTE)


	while (start_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetDrawBright(255, 255, 255);//���̏��������Ȃ��Ɖ摜�\�����o�O��܂��B(��ʋP�x���ő�ɐݒ�)

		//�ݒ�l��config����K���t�@�C��������������Ă���
		bgm.sound_volume = config.sound_data.bgm_volume;
		bgm.sound_volume *= -config.sound_data.bgm_mute;//�~���[�g�l�̓}�C�i�X���|���Ă��炶��Ȃ��Ƌt�ɂȂ�
		bgm.Play(1.0f, DX_PLAYTYPE_LOOP);

		DrawGraph(0, 0, back_wall_graphics, TRUE);//�w�i�摜��\��

		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//�t�F�[�h�A�E�g
		{

			//�j���[�Q�[���{�^��
			if (start.DrawStartButton(125 + start_pos_x, window_y - 265, wire) == 1)
			{
				StartScene::Init(config);//���������Ă���
				start_scene_flag = 1;//���[�v�𔲂���
			}

			//���[�h�{�^��
			if (load.DrawLoadButton(150 + load_pos_x, window_y - 210, wire) == 1)
			{
				flag = 2;//�t���O��2�ɂ���B
			}

			//�I�v�V�����{�^��
			if (option.DrawOptionButton(175 + option_pos_x, window_y - 155, wire) == 1)
			{
				flag = 3;//�t���O��3�ɂ���B
			}

			//�I���{�^��
			if (exit.DrawExitButton(200 + exit_pos_x, window_y - 100, wire) == 1)
			{
				StartScene::Init(config);//���������Ă���
				start_scene_flag = -1;//���[�v�𔲂���
			}

			//���[�h��ʂֈړ�����ۂ̏���
			if (flag == 2)
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
				{
					StartScene::Init(config);//���������Ă���
					flag = 0;//�t���O���O�ŏ��������Ă���
					start_scene_flag = 2;//���[�v�𔲂���
				}
			}

			//�I�v�V������ʂֈړ�����
			if (flag == 3)
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
				{
					if (option_scene.DrawOptionScene(window_x, window_y, config, wire) == true)
					{
						StartScene::Init(config);//���������Ă���
						flag = 0;
					}
				}
			}

			//�e�{�^���̃X���C�h�A�j���[�V����
			if (start_pos_x < 0)
			{
				start_pos_x += anime_x;
				if (start_pos_x >= 0)
				{
					start_pos_x = 0;
				}
			}

			if (load_pos_x < 0)
			{
				load_pos_x += anime_x;
				if (load_pos_x >= 0)
				{
					load_pos_x = 0;
				}
			}

			if (option_pos_x < 0)
			{
				option_pos_x += anime_x;
				if (option_pos_x >= 0)
				{
					option_pos_x = 0;
				}
			}

			if (exit_pos_x < 0)
			{
				exit_pos_x += anime_x;
				if (exit_pos_x >= 0)
				{
					exit_pos_x = 0;
				}
			}	
		}
	}
}