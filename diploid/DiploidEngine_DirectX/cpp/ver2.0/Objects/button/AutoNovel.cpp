#include "ver2.0/Objects/button/AutoNovel.h"

void AutoNovel::Load()
{
	//�A�j���[�V�����摜�̓ǂݍ���
	anime.Load("texter/novel/button/auto_novel/0.png");
	anime.Load("texter/novel/button/auto_novel/1.png");
	anime.Load("texter/novel/button/auto_novel/2.png");
	anime.Load("texter/novel/button/auto_novel/3.png");
	anime.Load("texter/novel/button/auto_novel/4.png");
	anime.Load("texter/novel/button/auto_novel/5.png");
	anime.Load("texter/novel/button/auto_novel/6.png");
	anime.Load("texter/novel/button/auto_novel/7.png");

}

void AutoNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//�{�^���̏�����
	anime.Init(pos, 8);//�A�j���[�V�����̏�����
	anime.SetAnimationSpeed(400);

	box.Init(VGet(pos.x, pos.y - 10, pos.z), VGet(0, 8, 0), GetColor(250, 250, 250));
	box.SetFill(true);
}

void AutoNovel::Update(DiploidEngineInput& input, int string_get_end_flag, float frame_time)
{
	anime.Update();//�A�j���[�V�����̃A�b�v�f�[�g
	button.Updata(&input);//�{�^���̃A�b�v�f�[�g

	if (button.GetSelectedUI() == 1)//�I����Ԃ̂Ƃ�
	{
		//�����̕`�悪�������Ă�����
		if (string_get_end_flag == 1)
		{
			if (time >= target_time)
			{
				next_flag = true;//���֍s��flag�𗧂Ă�
				time = 0;
			}
			else
			{
				next_flag = false;
				time += auto_speed * frame_time;//�I�[�g�̎��Ԃ�i�߂�B
			}
		}
		else
		{
			//������
			next_flag = false;
			time = 0;
		}

	}
	else//�I����ԂłȂ��Ƃ�
	{
		//������
		next_flag = false;
		time = 0;
	}	

	box.SetSize(VGet(time, 8, 0));//�I�[�g��time���r�W���A���ɔ��f
}

void AutoNovel::Draw(float frame_time, bool draw, bool debug)
{
	if (draw == true)
	{	
		box.Draw();

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


void AutoNovel::Reset()
{
	time = 0;
	button.SetSelectedUI(-1);
}


void AutoNovel::SetSpeed(float new_speed)
{
	auto_speed = new_speed;
}

void AutoNovel::SetSelected(int new_flag)
{
	button.SetSelectedUI(new_flag);
}


bool AutoNovel::GetHit()
{
	return button.GetHit();
}

bool AutoNovel::GetClick()
{
	return button.GetClick();
}

int AutoNovel::GetSelected()
{
	return button.GetSelectedUI();
}


bool AutoNovel::GetNextFlag()
{
	return next_flag;
}