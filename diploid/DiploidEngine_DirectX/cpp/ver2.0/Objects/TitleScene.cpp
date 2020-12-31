#include "ver2.0/Objects/TitleScene.h"

void TitleScene::Load()
{
	button_back_image.Load("texter/title/button_back.png");//�{�^���̔w�i�摜�̓ǂݍ���
	test_back.Load("texter/hd.jpg");//test�̔w�i�摜�̓ǂݍ���

	start_button.Load(button_back_image.GetGraphicsHandl());//�X�^�[�g�{�^���̉摜�n���h���̓ǂݍ���
	load_button.Load(button_back_image.GetGraphicsHandl());//�Z�[�u�f�[�^�ǂݍ��݃{�^���̉摜�n���h���̓ǂݍ���
	option_button.Load(button_back_image.GetGraphicsHandl());//�I�v�V�����{�^���̉摜�n���h���̓ǂݍ���
	exit_button.Load(button_back_image.GetGraphicsHandl());//�I���{�^���̉摜�n���h���̓ǂݍ��݁B


	start_string.CreateFontData(50, 10, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//�t�H���g�쐬

	//�����̓ǂݍ���
	start_string.Load("Start");//�X�^�[�g�{�^���̕�����̐ݒ�
	load_string.Load("Load");
	option_string.Load("Option");
	exit_string.Load("Exit");//�I���{�^���̕�����̐ݒ�
}

void TitleScene::Init()
{
	//�t�F�[�h�C���A�A�E�g�p��BOX�̏�����
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	//�e��{�^���̔z�u�ʒu��ݒ�
	start_button.Init(VGet(128, setting.window_y - 512, 0), button_back_image.GetSize());//�X�^�[�g�{�^���̏�����
	load_button.Init(VGet(128, setting.window_y - 512 + (button_back_image.GetSize().y + 20), 0), button_back_image.GetSize());//�ǂݍ��݃{�^���̏�����
	option_button.Init(VGet(128, setting.window_y - 512 + (button_back_image.GetSize().y + 20) * 2, 0), button_back_image.GetSize());//�I�v�V�����{�^���̏�����
	exit_button.Init(VGet(128, setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 3), 0), button_back_image.GetSize());//�I���{�^���̏�����

	start_string.Init(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512, start_string.GetHandle());
	load_string.Init(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512 + (button_back_image.GetSize().y + 20), start_string.GetHandle());
	option_string.Init(128 + (button_back_image.GetSize().x / 4), setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 2), start_string.GetHandle());
	exit_string.Init(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 3), start_string.GetHandle());

}

void TitleScene::Updata()
{
	SetBackgroundColor(0, 0, 0);

	//�e�{�^���̃A�b�v�f�[�g
	start_button.Updata(&input);
	load_button.Updata(&input);
	option_button.Updata(&input);
	exit_button.Updata(&input);

	//�ǂ̃{�^����������Ă��Ȃ�������
	if (button_click == GAME_TITLE)
	{
		//�X�^�[�g�{�^����������
		if (start_button.GetClick() == true)
		{
			start_button.SetSelectedUI(false);
			button_click = GAME_START;
		}

		//�ǂݍ��݃{�^����������
		if (load_button.GetClick() == true)
		{
			load_button.SetSelectedUI(false);
			button_click = GAME_LOAD;
		}

		//�I�v�V�����{�^����������
		if (option_button.GetClick() == true)
		{
			option_button.SetSelectedUI(false);
			button_click = GAME_OPTION;
		}

		//�Q�[���I���{�^�����������B
		if (exit_button.GetClick() == true)
		{
			exit_button.SetSelectedUI(false);
			button_click = GAME_EXIT;
		}
	}

	//�{�^������������
	if (button_click != GAME_TITLE)
	{
		alpha += alpha_speed;//���ߒl��ύX

		if (alpha > 255)//���ߒl�t���[����
		{
			alpha = 255;
			secen_select = button_click;//�������{�^���̎�ނ���
		}
	}
	else
	{
		if (alpha <= 0)//���ߒl�t���[����
		{
			alpha = 0;
		}
		alpha -= alpha_speed;//���ߒl��ύX
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

void TitleScene::Draw()
{
	test_back.Draw();

	start_button.Draw();
	start_string.Draw();

	load_button.Draw();
	load_string.Draw();

	option_button.Draw();
	option_string.Draw();

	exit_button.Draw();
	exit_string.Draw();

	//���U�C�N����
	//scr_gra.Draw(mosaic);


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

int TitleScene::GetFinalScene()
{
	return secen_select;
}

void TitleScene::SetSecne(int scene_type)
{
	secen_select = scene_type;
	button_click = scene_type;
}