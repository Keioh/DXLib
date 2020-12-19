#include "ver2.0/Objects/TitleScene.h"

void TitleScene::Load()
{
	button_back_image.Load("texter/title/button_back.png");//�{�^���̔w�i�摜�̓ǂݍ���
	test_back.Load("texter/hd.jpg");//test�̔w�i�摜�̓ǂݍ���

	start_button.Load(button_back_image.GetGraphicsHandl());//�X�^�[�g�{�^���̉摜�n���h���̓ǂݍ���
	load_button.Load(button_back_image.GetGraphicsHandl());//�Z�[�u�f�[�^�ǂݍ��݃{�^���̉摜�n���h���̓ǂݍ���
	option_button.Load(button_back_image.GetGraphicsHandl());//�I�v�V�����{�^���̉摜�n���h���̓ǂݍ���
	exit_button.Load(button_back_image.GetGraphicsHandl());//�I���{�^���̉摜�n���h���̓ǂݍ��݁B


	start_string.CreateFontData(50, 5, DX_FONTTYPE_NORMAL);//�t�H���g�쐬

	//�����̓ǂݍ���
	start_string.Load("Start");//�X�^�[�g�{�^���̕�����̐ݒ�

	load_string.Load("Load");
	load_string.ChangeFont(start_string.GetHandle());

	option_string.Load("Option");
	option_string.ChangeFont(start_string.GetHandle());

	exit_string.Load("Exit");//�I���{�^���̕�����̐ݒ�
	exit_string.ChangeFont(start_string.GetHandle());//�I���{�^���̕�����ɃX�^�[�g�{�^���Ŏg�p�����t�H���g���g�p����B

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
}

void TitleScene::Updata()
{
	SetBackgroundColor(0, 0, 0);

	//�e�{�^���̃A�b�v�f�[�g
	start_button.Updata(&input);
	load_button.Updata(&input);
	option_button.Updata(&input);
	exit_button.Updata(&input);


	if (alpha <= 0)//���ߒl�t���[����
	{
		alpha = 0;
	}
	else
	{		
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
	start_string.Draw(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512);

	load_button.Draw();
	load_string.Draw(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512 + (button_back_image.GetSize().y + 20));

	option_button.Draw();
	option_string.Draw(128 + (button_back_image.GetSize().x / 4), setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 2));

	exit_button.Draw();
	exit_string.Draw(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 3));

	scr_gra.Draw(mosaic);


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

int TitleScene::GetFinalScene()
{
	//�X�^�[�g�{�^����������
	if (start_button.GetClick() == true)
	{		
		start_button.SetSelectedUI(false);
		return GAME_START;
	}

	//�ǂݍ��݃{�^����������
	if (load_button.GetClick() == true)
	{	
		load_button.SetSelectedUI(false);
		return GAME_LOAD;
	}

	//�I�v�V�����{�^����������
	if (option_button.GetClick() == true)
	{
		option_button.SetSelectedUI(false);
		return GAME_OPTION;
	}

	//�Q�[���I���{�^�����������B
	if (exit_button.GetClick() == true)
	{	
		exit_button.SetSelectedUI(false);
		return GAME_EXIT;
	}

	return GAME_NONE;
}