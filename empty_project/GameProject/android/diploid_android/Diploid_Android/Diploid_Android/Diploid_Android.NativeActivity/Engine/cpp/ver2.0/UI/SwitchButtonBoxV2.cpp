#include "ver2.0/UI/SwitchButtonBoxV2.h"


void SwitchButtonBoxV2::Init(VECTOR pos, VECTOR size, int mouse_button)
{
	//�}�E�X�{�^����ۑ�
	mouse_button_type = mouse_button;

	//BOX�̏�����
	box.Init(pos, size, GetColor(255, 255, 255));
	//box.SetFill(TRUE);
}

void SwitchButtonBoxV2::Update()
{
	//�C���v�b�g�A�b�v�f�[�g
	input.Update();

	//�����蔻�菈��(�}�E�X��BOX)
	if (collision.BoxAndMouseCollisionUpdate(&box, input.GetMousePosition().x, input.GetMousePosition().y) == true)
	{
		//�{�^���ɓ������Ă��邩�̃t���O��true��
		button_hit_flag = true;

		//�F�ɕύX
		box.SetColor(GetColor(0, 0, 255));

		//�}�E�X�̃N���b�N����
		if (input.GetPressMouse(mouse_button_type) == true)
		{
			//�{�^�����N���b�N�������̃t���O��true��
			button_click_flag = true;

			//�{�^����I�𒆂��̃t���O��ύX
			button_selected_flag *= -1;

			//button_selected_flag��1�Ȃ�
			if (button_selected_flag == -1)
			{
				//�ΐF�ɕύX
				box.SetColor(GetColor(0, 255, 0));
			}
			else
			{
				//�ԐF�ɕύX
				box.SetColor(GetColor(255, 0, 0));
			}
		}
		else
		{
			//�{�^�����N���b�N�������̃t���O��false��
			button_click_flag = false;
		}
	}
	else
	{
		//���邢�D�F�ɕύX
		box.SetColor(GetColor(200, 200, 200));


		//�{�^���ɓ������Ă��邩�̃t���O��false��
		button_hit_flag = false;
	}
}

void SwitchButtonBoxV2::Draw(bool draw )
{
	if (draw == true)
	{
		//�����蔻��BOX�̕\��
		box.Draw(draw);
	}
}


bool SwitchButtonBoxV2::GetHit()
{
	return button_hit_flag;
}

bool SwitchButtonBoxV2::GetClick()
{
	return button_click_flag;
}

int SwitchButtonBoxV2::GetSelected()
{
	return button_selected_flag;
}


DiploidBoxV2& SwitchButtonBoxV2::GetBoxPtr()
{
	return box;
}