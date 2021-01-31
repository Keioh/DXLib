#include "ver2.0/Objects/OptionScene.h"

void OptionScene::Load()
{
	//�߂�{�^���̓ǂݍ���
	back_button.Load();

	//�ۑ��{�^���̓ǂݍ���
	save_button.Load();
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

}

void OptionScene::Updata(DiploidEngineInput& input)
{
	SetBackgroundColor(255, 255, 255);//Window�w�i�F�𔒐F�ɕύX


	save_button.Update(input);//�ۑ��{�^���̍X�V����

	back_button.Update(input);//�߂�{�^���̍X�V����

	if (back_button.GetClick() == true)//�߂�{�^�����N���b�N���ꂽ��
	{
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