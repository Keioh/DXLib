#include "OptionScene.h"

OptionScene::OptionScene()
{
	flag = false;
	OptionScene::Init();
}

void OptionScene::Load()
{
	back_wall_graphics = LoadGraph("pack/UI/option/option_back_wall.png");

	bgm_volume.LoadGraphics();
	se_volume.LoadGraphics();

	bgm_mute.LoadGraphics();
	se_mute.LoadGraphics();

	fade_in.LoadGraphics();
	fade_out.LoadGraphics();

	save_and_return.LoadGraphics();
}

void OptionScene::Init()
{
	option_scene_flag = 0;

	bgm_volume.init();
	se_volume.init();

	bgm_mute.init();
	se_mute.init();

	fade_in.init();
	fade_out.init();

	save_and_return.init();
}

void OptionScene::DrawOptionScene(int window_x, int window_y, Filer config, bool wire)
{		
	bgm_volume.bgm_volume_slider.wheel_volume_buffer = config.sound_data.bgm_volume;//BGM���ʂ�ݒ�t�@�C������ݒ肷��B
	se_volume.se_volume_slider.wheel_volume_buffer = config.sound_data.se_volume;//SE���ʂ�ݒ�t�@�C������ݒ肷��B
	bgm_mute.bgm_mute.switch_flag = config.sound_data.bgm_mute;//BGM�~���[�g��ݒ�t�@�C������ݒ肷��B
	se_mute.se_mute.switch_flag = config.sound_data.se_mute;//SE�~���[�g��ݒ�t�@�C������ݒ肷��B

	while (option_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetDrawBright(255, 255, 255);//���̏��������Ȃ��Ɖ摜�\�����o�O��܂��B(��ʋP�x���ő�ɐݒ�)
		DrawGraph(0, 0, back_wall_graphics, TRUE);

		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//�t�F�[�h�A�E�g
		{		

			bgm_volume.DrawBGMVolumeSlider(200, 200, GetColor(0, 0, 255), wire);//BGM���ʒ���
			bgm_mute.DrawBGMMuteButton(200 + 255 + 20, 200 + 5, wire);//BGM�~���[�g

			se_volume.DrawSEVolumeSlider(200, 250, GetColor(0, 0, 255), wire);//SE���ʒ���
			se_mute.DrawSEMuteButton(200 + 255 + 20, 250 + 5, wire);//SE�~���[�g

			//�ݒ���Z�[�u���Ă���I�v�V������ʂ��甲����{�^��
			if (save_and_return.DrawSaveAndReturnButton(window_x - (50 + save_and_return.save_and_return.size_x), window_y - (50 + save_and_return.save_and_return.size_y), wire) == 1)
			{
				flag = true;
			}

			if (flag == true)//�t�F�[�h�C��
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
				{
					OptionScene::Init();//���������Ă���
					flag = false;
					option_scene_flag = 1;//���[�v�𔲂���
				}
			}
		}
	}
}