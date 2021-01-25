#include "ver2.0/Objects/button/SkipNovel.h"

void SkipNovel::Load()
{
	//�A�j���[�V�����摜�̓ǂݍ���
	anime.Load("texter/novel/button/skip/0.png");
	anime.Load("texter/novel/button/skip/1.png");
	anime.Load("texter/novel/button/skip/2.png");
	anime.Load("texter/novel/button/skip/3.png");
}

void SkipNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//�{�^���̏�����
	anime.Init(pos);//�A�j���[�V�����̏�����

	box.Init(VGet(pos.x, pos.y - 10, pos.z), VGet(0, 8, 0), GetColor(250, 250, 250));
	box.SetFill(true);
}

void SkipNovel::Update(DiploidEngineInput& input)
{
	anime.Update();//�A�j���[�V�����̃A�b�v�f�[�g
	button.Updata(&input);//�{�^���̃A�b�v�f�[�g

	if (button.GetSelectedUI() == 1)//�I����Ԃ̂Ƃ�
	{
		if (time > next_time)
		{
			next_flag = 1;//���֍s��flag�𗧂Ă�
			time = 0;
		}
		else
		{
			time += skip_speed;
			next_flag = 0;
		}
	}
	else//�I����ԂłȂ��Ƃ�
	{
		time = 0;

		//������
		next_flag = -1;
	}	
}

void SkipNovel::Draw(bool draw, bool debug)
{
	if (draw == true)
	{	
		box.Draw();

		if ((button.GetSelectedUI() == 1) && (next_flag >= 0))//�I����Ԃ̂Ƃ��A����next_flag���O�ȏ�̂Ƃ�
		{
			SetDrawBright(255, 255, 255);
			anime.StackDraw();//�A�j���[�V�����̕`��(�X�^�b�N�`��)
		}
		else//�I����Ԃ���Ȃ��Ƃ�
		{
			if (button.GetHit() == true)//�J�[�\�����{�^���ɓ������Ă���
			{
				SetDrawBright(255  * 0.9, 255 *  0.9, 255 * 0.9);
				anime.StackDraw();//�A�j���[�V�����̕`��(�X�^�b�N�`��)
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


void SkipNovel::SetSelected(int new_flag)
{
	if (new_flag == 1)
	{
		next_flag = 0;
	}

	if (new_flag == -1)
	{
		next_flag = -1;
	}

	button.SetSelectedUI(new_flag);
}


bool SkipNovel::GetHit()
{
	return button.GetHit();
}

bool SkipNovel::GetClick()
{
	return button.GetClick();
}

int SkipNovel::GetSelected()
{
	return button.GetSelectedUI();
}


int SkipNovel::GetNextFlag()
{
	return next_flag;
}