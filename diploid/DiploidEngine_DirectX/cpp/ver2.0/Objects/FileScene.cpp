#include "ver2.0/Objects/FileScene.h"

void FileScene::Load()
{
	load_string_image.Load();

	back_button.Load();
}

void FileScene::Init()
{
	//�t�F�[�h�pBOX
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	load_string_image.Init(VGet(0, 0, 0));


	//�߂�{�^��
	back_button.Init(VGet(setting.window_x - (128 + 4), setting.window_y - (32 + 4), 0));
}

void FileScene::Updata()
{
	SetBackgroundColor(255, 255, 255);

	load_string_image.Updata();

	//�߂�{�^��
	back_button.Update(input);

	//�t�F�[�h�A�E�g�������Ă�����
	if (box_draw_flag == 1)
	{
		//�߂�{�^�����N���b�N������
		if (back_button.GetClick() == true)
		{
			back_button.SetSelectedFlag(1);
			box_draw_flag = 2;
		}
	}

	//�V�[�����n�܂�����
	if (box_draw_flag == 0)//�t�F�[�h�A�E�g�n��
	{
		alpha -= alpha_speed;//���ߒl��ύX

		if (alpha <= 0)//���ߒl�t���[����
		{
			alpha = 0;
			box_draw_flag = 1;//�t�F�[�h�A�E�g����
		}
	}

	if (box_draw_flag == 2)//�t�F�[�h�C���n��
	{
		alpha += alpha_speed;//���ߒl��ύX

		if (alpha > 255)//���ߒl�t���[����
		{
			alpha = 255;
			box_draw_flag = 3;//�t�F�[�h�C������
		}
	}


	if (mosaic >= mosaic_max)//���U�C�N�l�t���[����
	{
		mosaic = mosaic_max;
	}
	else
	{
		mosaic += mosaic_speed;//���U�C�N�l��ύX
	}
}

void FileScene::Draw()
{
	load_string_image.Draw();

	//�߂�{�^��
	back_button.Draw();

	//���U�C�N����
	//scr_gra.Draw(mosaic);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

int FileScene::GetReturnButton()
{
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		load_string_image.Reset();

		box_draw_flag = 0;//�t�F�[�h�A�E�g��flag�𗧂Ă�
		back_button.SetSelectedFlag(-1);
		return GAME_TITLE;
	}

	return GAME_NONE;
}

void FileScene::SetSecne(int scene_type)
{
	secen_select = scene_type;
	button_click = scene_type;
}