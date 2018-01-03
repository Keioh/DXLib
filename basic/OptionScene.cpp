#include "OptionScene.h"

OptionScene::OptionScene()
{
	flag = false;
	OptionScene::Init();
}

void OptionScene::Load()
{
	fade_in.LoadGraphics();
	fade_out.LoadGraphics();

	save_and_return.LoadGraphics();

	test.Load("pack/UI/ButtonUI/wheel_horizontal.png");
}

void OptionScene::Init()
{
	option_scene_flag = 0;

	fade_in.init();
	fade_out.init();

	test.Init();

	save_and_return.init();
}

void OptionScene::DrawOptionScene(int window_x, int window_y, bool wire)
{
	while (option_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//�t�F�[�h�A�E�g
		{
			DrawString(0, 0, "OptionScene", GetColor(0, 0, 0));

			test.BoxUI_WheelHorizontal(200, 200, wire);

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