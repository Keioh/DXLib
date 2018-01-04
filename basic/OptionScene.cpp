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

	fade_in.LoadGraphics();
	fade_out.LoadGraphics();

	save_and_return.LoadGraphics();

}

void OptionScene::Init()
{
	option_scene_flag = 0;

	bgm_volume.init();
	se_volume.init();

	fade_in.init();
	fade_out.init();

	save_and_return.init();
}

void OptionScene::DrawOptionScene(int window_x, int window_y, bool wire)
{
	while (option_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetDrawBright(255, 255, 255);//���̏��������Ȃ��Ɖ摜�\�����o�O��܂��B(��ʋP�x���ő�ɐݒ�)
		DrawGraph(0, 0, back_wall_graphics, TRUE);

		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//�t�F�[�h�A�E�g
		{		

			bgm_volume.DrawBGMVolumeSlider(100, 200, GetColor(0, 0, 255), wire);//BGM���ʒ���
			se_volume.DrawSEVolumeSlider(100, 250, GetColor(0, 0, 255), wire);//SE���ʒ���

			//�ݒ���Z�[�u���Ă���I�v�V������ʂ��甲����{�^��
			if (save_and_return.DrawSaveAndReturnButton(window_x - (10 + save_and_return.save_and_return.size_x), window_y - (10 + save_and_return.save_and_return.size_y), wire) == 1)
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