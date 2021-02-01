#include "ver2.0/Objects/OptionScene.h"

void OptionScene::Load()
{
	//�߂�{�^���̓ǂݍ���
	back_button.Load();

	//�ۑ��{�^���̓ǂݍ���
	save_button.Load();

	//�E�B���h�E�T�C�Y�ύX�{�^���̉摜�ǂݍ���
	window_resize_button_960_540.Load("texter/basic/button/display/960_540.png");
	window_resize_button_1280_720.Load("texter/basic/button/display/1280_720.png");
	window_resize_button_1600_900.Load("texter/basic/button/display/1600_900.png");
	window_resize_button_1920_1080.Load("texter/basic/button/display/1920_1080.png");

}

void OptionScene::Init(DiploidEngineSetting& setting)
{
	//�t�F�[�h�pBOX
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	//�߂�{�^��
	back_button.Init(VGet(setting.window_x - (128 + 4), setting.window_y - (32 + 4), 0));

	//�ۑ��{�^��
	save_button.Init(VGet(setting.window_x - ((128 * 2) + 4), setting.window_y - (32 + 4), 0));

	//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)
	window_resize_button_960_540.SetWindowSize(960, 540);//�^�[�Q�b�g�ƂȂ�E�B���h�E�T�C�Y���w��
	window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y, 0), setting);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)
	window_resize_button_1280_720.SetWindowSize(1280, 720);//�^�[�Q�b�g�ƂȂ�E�B���h�E�T�C�Y���w��
	window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)	
	window_resize_button_1600_900.SetWindowSize(1600, 900);//�^�[�Q�b�g�ƂȂ�E�B���h�E�T�C�Y���w��
	window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 2), 0), setting);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)	
	window_resize_button_1920_1080.SetWindowSize(1920, 1080);//�^�[�Q�b�g�ƂȂ�E�B���h�E�T�C�Y���w��
	window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
}

void OptionScene::Updata(DiploidEngineInput& input, DiploidEngineSetting& setting)
{
	SetBackgroundColor(255, 255, 255);//Window�w�i�F�𔒐F�ɕύX

	//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)
	window_resize_button_960_540.Update(input);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)
	window_resize_button_1280_720.Update(input);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)
	window_resize_button_1600_900.Update(input);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)
	window_resize_button_1920_1080.Update(input);


	//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)���N���b�N���ꂽ�Ƃ�
	if (window_resize_button_960_540.GetClick() == true)
	{
		window_resize_button_960_540.SetSelectedFlag(1);

		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)���N���b�N���ꂽ�Ƃ�
	if (window_resize_button_1280_720.GetClick() == true)
	{
		window_resize_button_1280_720.SetSelectedFlag(1);

		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)���N���b�N���ꂽ�Ƃ�
	if (window_resize_button_1600_900.GetClick() == true)
	{
		window_resize_button_1600_900.SetSelectedFlag(1);	
		
		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)���N���b�N���ꂽ�Ƃ�
	if (window_resize_button_1920_1080.GetClick() == true)
	{
		window_resize_button_1920_1080.SetSelectedFlag(1);

		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
	}


	save_button.Update(input);//�ۑ��{�^���̍X�V����

	if ((save_button.GetClick() == true) && (save_button.GetHit() == true))//�ۑ��{�^�����������Ƃ�
	{
		//�E�B���h�E�T�C�Y960_540���I����ԂȂ�
		if (window_resize_button_960_540.GetSelected() == 1)
		{
			setting.SetWindowSize(960, 540);//�𑜓x��ύX
		}

		//�E�B���h�E�T�C�Y1280_720���I����ԂȂ�
		if (window_resize_button_1280_720.GetSelected() == 1)
		{
			setting.SetWindowSize(1280, 720);//�𑜓x��ύX
		}

		//�E�B���h�E�T�C�Y1600_900���I����ԂȂ�
		if (window_resize_button_1600_900.GetSelected() == 1)
		{
			setting.SetWindowSize(1600, 900);//�𑜓x��ύX
		}

		//�E�B���h�E�T�C�Y1920_1080���I����ԂȂ�
		if (window_resize_button_1920_1080.GetSelected() == 1)
		{
			setting.SetWindowSize(1920, 1080);//�𑜓x��ύX
		}
	}


	back_button.Update(input);//�߂�{�^���̍X�V����

	if (back_button.GetClick() == true)//�߂�{�^�����N���b�N���ꂽ��
	{
		//���݂̉𑜓x�̃{�^���Ƀ`�F�b�N��t���Ȃ����B
		window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y, 0), setting);
		window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
		window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 2), 0), setting);
		window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);

		back_button.SetSelectedFlag(1);//�I����Ԃ�1���ێ�
		box_draw_flag = 2;//�t�F�[�h�C�����n�߂�
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
}

void OptionScene::Draw(bool draw, bool debug)
{	
	//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)
	window_resize_button_960_540.Draw(draw, debug);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)
	window_resize_button_1280_720.Draw(draw, debug);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)
	window_resize_button_1600_900.Draw(draw, debug);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)
	window_resize_button_1920_1080.Draw(draw, debug);


	//�ۑ��{�^��
	save_button.Draw(draw, debug);

	//�߂�{�^��
	back_button.Draw(draw, debug);

	//�t�F�[�h�A�E�g�pBOX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}


bool OptionScene::GetReturnFlag()
{
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//�t�F�[�h�A�E�g��flag�𗧂Ă�
		back_button.SetSelectedFlag(-1);//�{�^���̑I����Ԃ�-1(������)�ɂ���B
		return true;
	}

	return false;
}
