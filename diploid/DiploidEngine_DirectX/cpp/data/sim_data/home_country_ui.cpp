#include "data/sim_data/home_country_ui.h"


void CommandUI::Load()
{
	military_graphics.Load("texter/sim_texter/military.png");//�R���R�}���h�̉摜�̓ǂݍ���
	production_graphics.Load("texter/sim_texter/production.png");//���Y�R�}���h�̉摜�̓ǂݍ���
	construction_graphics.Load("texter/sim_texter/construction.png");//���݃R�}���h�̉摜�̓ǂݍ���
	politics_graphics.Load("texter/sim_texter/politics.png");//�����R�}���h�̉摜�̓ǂݍ���

	military.Load(military_graphics.GetGraphicsHandl());//�R���R�}���h�̉摜�n���h����n���B
	production.Load(production_graphics.GetGraphicsHandl());//���Y�R�}���h�̉摜�n���h����n���B
	construction.Load(construction_graphics.GetGraphicsHandl());//���݃R�}���h�̉摜�n���h����n���B
	politics.Load(politics_graphics.GetGraphicsHandl());//�����R�}���h�̉摜�n���h����n���B

}

void CommandUI::Init(VECTOR pos, float scale)
{
	//�R���R�}���h
	military.Init(pos, VGet(512, 256, 0), scale);

	//���݃R�}���h
	construction.Init(VGet(pos.x, pos.y + (256 * scale), 0.0f), VGet(512, 256, 0), scale);

	//�����R�}���h
	politics.Init(VGet(pos.x, pos.y + ((256 * 2) * scale), 0.0f), VGet(512, 256, 0), scale);


	//���Y�R�}���h
	production.Init(VGet(pos.x + (512 * scale), pos.y, 0.0f), VGet(512, 256, 0), scale);

}

void CommandUI::Updata(DiploidEngineInput* input)
{
	if (collision_active_flag == true)//�����蔻��t���O���I����������
	{
		//�R���R�}���h�̍X�V
		military.Updata(input);

		//���݃R�}���h�̍X�V
		construction.Updata(input);

		//�����R�}���h�̍X�V
		politics.Updata(input);


		//�R���R�}���h���N���b�N���ꂽ��
		if (military.GetClick() == true)
		{
			//�����R�}���h���I�t�ɂ���B
			politics.SetSelectedUI(-1);

			//���݃R�}���h���I�t�ɂ���B
			construction.SetSelectedUI(-1);
		}

		//���݃R�}���h���N���b�N���ꂽ��
		if (construction.GetClick() == true)
		{
			//�R���R�}���h���I�t�ɂ���B
			military.SetSelectedUI(-1);

			//�����R�}���h���I�t�ɂ���B
			politics.SetSelectedUI(-1);
		}

		//�����R�}���h���N���b�N���ꂽ��
		if (politics.GetClick() == true)
		{
			//�R���R�}���h���I�t�ɂ���B
			military.SetSelectedUI(-1);

			//���݃R�}���h���I�t�ɂ���B
			construction.SetSelectedUI(-1);
		}


		//�R���R�}���h���I������Ă���
		if (military.GetSelectedUI() == 1)
		{	
			//���Y�R�}���h�̍X�V
			production.Updata(input);
		}
		else
		{
			//���Y�R�}���h���I�t�ɂ���B
			production.SetSelectedUI(-1);
		}


		//���݃R�}���h���I������Ă��Ȃ�������
		if (construction.GetSelectedUI() == -1)
		{

		}
	}
}

void CommandUI::Draw(bool draw, bool debug)
{
	if (draw == true)
	{	
		//�R���R�}���h�̕`��
		military.Draw(draw, debug);

		//���݃R�}���h�̕`��
		construction.Draw(draw, debug);

		//�����R�}���h�̕`��
		politics.Draw(draw, debug);


		//�R���R�}���h���I������Ă�����
		if (military.GetSelectedUI() == 1)
		{
			//���Y�R�}���h�̕`��
			production.Draw(draw, debug);
		}
	}
}


bool CommandUI::GetHit()
{
	if ((military.GetHit() || production.GetHit() || construction.GetHit() || politics.GetHit()) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CommandUI::ResetFlag()
{
	military.SetSelectedUI(-1);
	construction.SetSelectedUI(-1);
	production.SetSelectedUI(-1);
	politics.SetSelectedUI(-1);
}

void CommandUI::SetCollisionActiveFlag(bool flag)
{
	collision_active_flag = flag;
}

bool CommandUI::GetCollisionActiveFlag()
{
	return collision_active_flag;
}