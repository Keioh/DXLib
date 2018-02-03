#include "LogoScene.h"

LogoScene::LogoScene()
{
	LogoScene::init();
}

void LogoScene::init()
{
	logo.Inti();

	fade_in.init();
	fade_out.init();

	logo_scene_flag = 0;
}

void LogoScene::Load()
{
	logo.LoadGraphics();
	
	fade_in.LoadGraphics();
	fade_out.LoadGraphics();

	logo_sound.LoadSound("pack/Logo/sound/logo_sound.wav");
}

void LogoScene::DrawLogoScene(int x, int y, Filer config)
{
	while (logo_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//�t�F�[�h�A�E�g
		{
			logo_sound.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);//�����Đ�

			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)//�}�E�X�����N���b�N������
			{
				LogoScene::init();//������
				logo_sound.Stop();//�����~
				logo_scene_flag = 1;//���S�V�[���𔲂���
			}

			logo.DrawLogo(x, y);//�t�F�[�h�A�E�g�����������烍�S��\��

			if (logo.anime_pos_x >= logo.anime_x)
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)//�t�F�[�h�C��
				{
					LogoScene::init();//������
					logo_sound.Stop();//�����~
					logo_scene_flag = 1;//�t�F�[�h�C�������������烍�S�V�[���𔲂���
				}
			}
		}
	}		
	logo_sound.SoundDelete();//���S�T�E���h���폜
	SetBackgroundColor(0, 0, 0);//�w�i�F�����ɐݒ�
}