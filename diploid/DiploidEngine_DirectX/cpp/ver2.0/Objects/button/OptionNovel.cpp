#include "ver2.0/Objects/button/OptionNovel.h"

void OptionNovel::Load()
{
	//�A�j���[�V�����摜�̓ǂݍ���
	anime.Load("texter/novel/button/option/0.png");
	anime.Load("texter/novel/button/option/1.png");
	anime.Load("texter/novel/button/option/2.png");
	anime.Load("texter/novel/button/option/3.png");
	anime.Load("texter/novel/button/option/4.png");
}

void OptionNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//�{�^���̏�����
	anime.Init(pos, 5);//�A�j���[�V�����̏�����
	anime.SetAnimationSpeed(5);
}

void OptionNovel::Update(DiploidEngineInput& input)
{
	anime.Update();//�A�j���[�V�����̃A�b�v�f�[�g
	button.Updata(&input);//�{�^���̃A�b�v�f�[�g
}

void OptionNovel::Draw(bool draw, bool debug)
{
	if (draw == true)
	{	
		if (button.GetSelectedUI() == 1)//�I����Ԃ̂Ƃ�
		{
			SetDrawBright(255, 255, 255);
			anime.Draw();//�A�j���[�V�����̕`��(�X�^�b�N�`��)
			//anime.StackDraw();//�A�j���[�V�����̕`��
		}
		else//�I����Ԃ���Ȃ��Ƃ�
		{
			if (button.GetHit() == true)//�J�[�\�����{�^���ɓ������Ă���
			{
				SetDrawBright(255  * 0.9, 255 *  0.9, 255 * 0.9);
				//anime.StackDraw();//�A�j���[�V�����̕`��(�X�^�b�N�`��)
				anime.Draw();//�A�j���[�V�����̕`��
				SetDrawBright(255, 255, 255);
			}
			else//�������Ă��Ȃ�
			{
				SetDrawBright(255  * 0.8, 255 * 0.8, 255 * 0.8);
				anime.Reset();//�R�}���ŏ�����Đ�(������)
				anime.OneCellDraw();//�ŏ���0�R�}�ڂ�`��
				SetDrawBright(255, 255, 255);
			}
		}
	}

	if (debug == true)
	{
		button.Draw();//�{�^���̕`��
	}
}


void OptionNovel::Reset()
{
	button.SetSelectedUI(-1);
}


void OptionNovel::SetSelected(int new_flag)
{
	button.SetSelectedUI(new_flag);
}


bool OptionNovel::GetHit()
{
	return button.GetHit();
}

bool OptionNovel::GetClick()
{
	return button.GetClick();
}

int OptionNovel::GetSelected()
{
	return button.GetSelectedUI();
}