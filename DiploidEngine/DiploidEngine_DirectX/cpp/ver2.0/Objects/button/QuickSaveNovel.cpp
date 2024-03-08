#include "ver2.0/Objects/button/QuickSaveNovel.h"

void QuickSaveNovel::Load()
{
	//�A�j���[�V�����摜�̓ǂݍ���
	anime.Load("texter/novel/button/q_save_novel/0.png");
	anime.Load("texter/novel/button/q_save_novel/1.png");
	anime.Load("texter/novel/button/q_save_novel/2.png");
	anime.Load("texter/novel/button/q_save_novel/3.png");
	anime.Load("texter/novel/button/q_save_novel/4.png");
}

void QuickSaveNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//�{�^���̏�����
	anime.Init(pos, 5);//�A�j���[�V�����̏�����
	anime.SetAnimationSpeed(300);
}

void QuickSaveNovel::Update(DiploidEngineInput& input, float frame_time)
{
	anime.Update();//�A�j���[�V�����̃A�b�v�f�[�g
	button.Updata(&input);//�{�^���̃A�b�v�f�[�g
}

void QuickSaveNovel::Draw(float frame_time, bool draw, bool debug)
{
	if (draw == true)
	{	
		if (button.GetSelectedUI() == 1)//�I����Ԃ̂Ƃ�
		{
			SetDrawBright(255, 255, 255);
			anime.Draw(frame_time);//�A�j���[�V�����̕`��
			//anime.StackDraw();
		}
		else//�I����Ԃ���Ȃ��Ƃ�
		{
			if (button.GetHit() == true)//�J�[�\�����{�^���ɓ������Ă���
			{
				SetDrawBright(255  * 0.9, 255 *  0.9, 255 * 0.9);
				anime.Draw(frame_time);//�A�j���[�V�����̕`��
				//anime.StackDraw();//�A�j���[�V�����̕`��(�X�^�b�N�`��)
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


void QuickSaveNovel::Reset()
{
	button.SetSelectedUI(-1);
}

void QuickSaveNovel::SetSelected(int new_flag)
{
	button.SetSelectedUI(new_flag);
}


bool QuickSaveNovel::GetHit()
{
	return button.GetHit();
}

bool QuickSaveNovel::GetClick()
{
	return button.GetClick();
}

int QuickSaveNovel::GetSelected()
{
	return button.GetSelectedUI();
}