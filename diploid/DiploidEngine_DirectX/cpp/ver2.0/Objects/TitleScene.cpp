#include "ver2.0/Objects/TitleScene.h"

void TitleScene::Load()
{
	button_back_image.Load("texter/title/button_back.png");//�{�^���̔w�i�摜�̓ǂݍ���
	test_back.Load("texter/novel/title/title.png");//test�̔w�i�摜�̓ǂݍ���

	start_button.Load(button_back_image.GetGraphicsHandl());//�X�^�[�g�{�^���̉摜�n���h���̓ǂݍ���
	load_button.Load(button_back_image.GetGraphicsHandl());//�Z�[�u�f�[�^�ǂݍ��݃{�^���̉摜�n���h���̓ǂݍ���
	option_button.Load(button_back_image.GetGraphicsHandl());//�I�v�V�����{�^���̉摜�n���h���̓ǂݍ���
	exit_button.Load(button_back_image.GetGraphicsHandl());//�I���{�^���̉摜�n���h���̓ǂݍ��݁B


	start_string.CreateFontData(40, 10, DX_FONTTYPE_ANTIALIASING_4X4, "���C���I");//�t�H���g�쐬

	//�����̓ǂݍ���
	start_string.CreateDXLIB("�͂��߂���", DX_CHARCODEFORMAT_SHIFTJIS);//�X�^�[�g�{�^���̕�����̐ݒ�
	load_string.CreateDXLIB("�Â�����", DX_CHARCODEFORMAT_SHIFTJIS);
	option_string.CreateDXLIB("�ݒ�", DX_CHARCODEFORMAT_SHIFTJIS);
	exit_string.CreateDXLIB("�I��", DX_CHARCODEFORMAT_SHIFTJIS);//�I���{�^���̕�����̐ݒ�
}

void TitleScene::Init(DiploidEngineSetting& setting)
{
	//�t�F�[�h�C���A�A�E�g�p��BOX�̏�����
	box.Init(VGet(0, 0, 0), VGet(setting.GetSystemData().window_x, setting.GetSystemData().window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	//�e��{�^���̔z�u�ʒu��ݒ�
	start_button.Init(VGet(128, setting.GetSystemData().window_y - (72 * 4) - 64, 0), button_back_image.GetSize());//�X�^�[�g�{�^���̏�����
	load_button.Init(VGet(128, setting.GetSystemData().window_y - (72 * 3) - 64, 0), button_back_image.GetSize());//�ǂݍ��݃{�^���̏�����
	option_button.Init(VGet(128, setting.GetSystemData().window_y - (72 * 2) - 64, 0), button_back_image.GetSize());//�I�v�V�����{�^���̏�����
	exit_button.Init(VGet(128, setting.GetSystemData().window_y - 72 - 64, 0), button_back_image.GetSize());//�I���{�^���̏�����

	start_string.Init(128, setting.GetSystemData().window_y - (72 * 4) - 64, start_string.GetHandle());
	start_string.SetSpeed(5000);
	load_string.Init(128, setting.GetSystemData().window_y - (72 * 3) - 64, start_string.GetHandle());
	load_string.SetSpeed(5000);
	option_string.Init(128, setting.GetSystemData().window_y - (72 * 2) - 64, start_string.GetHandle());
	option_string.SetSpeed(5000);
	exit_string.Init(128, setting.GetSystemData().window_y - 72 - 64, start_string.GetHandle());
	exit_string.SetSpeed(5000);

	//��ʂ̑傫���ɍ��킹��
	test_back.Init(VGet(0, 0, 0));
	test_back.SetScale((float)setting.GetSystemData().window_x / test_back.GetSize().x, (float)setting.GetSystemData().window_y / test_back.GetSize().y);
}

void TitleScene::Updata(DiploidEngineScreen& screen)
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
			button_click = GAME_FILE;
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
		alpha += alpha_speed * screen.GetFrameTime();//���ߒl��ύX

		if (alpha > 255)//���ߒl�t���[����
		{
			alpha = 255;
			secen_select = button_click;//�������{�^���̃V�[����ނ���
		}
	}
	else
	{
		if (alpha <= 0)//���ߒl�t���[����
		{
			alpha = 0;
		}
		alpha -= alpha_speed * screen.GetFrameTime();//���ߒl��ύX
	}


	if (mosaic >= mosaic_max)//���U�C�N�l�t���[����
	{
		mosaic = mosaic_max;
	}
	else
	{
		mosaic += mosaic_speed * screen.GetFrameTime();//���U�C�N�l��ύX
	}
}

void TitleScene::Draw(DiploidEngineScreen& screen)
{
	test_back.Draw();

	start_button.Draw();
	start_string.Draw(screen.GetFrameTime());

	load_button.Draw();
	load_string.Draw(screen.GetFrameTime());

	option_button.Draw();
	option_string.Draw(screen.GetFrameTime());

	exit_button.Draw();
	exit_string.Draw(screen.GetFrameTime());

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