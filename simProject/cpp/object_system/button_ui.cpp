#include "button_ui.h"

ButtonUI::ButtonUI()
{
	ButtonUI::Init();
}

void ButtonUI::Load(char* path, char* switch_path)
{
	graphics = LoadGraph(path);
	switch_graphics = LoadGraph(switch_path);
}

void ButtonUI::Init()
{
	mouse_input.init();
	//color = GetColor(100, 100, 100);
	wheel_volume_buffer = 0;
	wheel_volume = 0;
	switch_flag = -1;
	box_collision.hit = 0;
	circle_collision.hit = 0;
}

void ButtonUI::ColliderOff()
{
	box_collision.active = false;
	circle_collision.active = false;
}

void ButtonUI::ColliderOn()
{
	box_collision.active = true;
	circle_collision.active = true;
}

int ButtonUI::BoxUI_Button_BOX(int pos_x, int pos_y, float Size_x, float Size_y, int input, bool wire)//�o�O�ɂ��X�P�[���̒l��1.0f�Ŏg�����ƁB�i�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B�j
{
	SetDrawBright(255, 255, 255);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)

	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	DrawBox(pos_x, pos_y, pos_x + Size_x, pos_y + Size_y, color, TRUE);
	DrawExtendGraphF(pos_x, pos_y, (pos_x + Size_x) * scale_x, (pos_y + Size_y) * scale_y, graphics, TRUE);//�摜���k���g��\��

	if (box_collision.BoxColliderMouse(pos_x, Size_x, pos_y, Size_y, wire) == true)//�R���W�����q�b�g����
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//�N���b�N����
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;

		click_flag = false;
	}

	if (click_flag == 1)//�N���b�N���ꂽ�Ƃ�wire�t���O��true��������O�����[�񃏃C���[��\��
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox((pos_x + double_line), (pos_y + double_line), (pos_x + (Size_x - double_line)), (pos_y + (Size_y - double_line)), GetColor(0, 255, 0), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���Bfor���͐��𑾂����鏈��)
			}
		}
	}
	SetDrawBright(255, 255, 255);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)

	return click_flag;//�N���b�N����̌��ʂ�Ԃ��B
}

int ButtonUI::BoxUI_Button(int pos_x, int pos_y, int input, bool wire)
{
	GetGraphSize(graphics, &size_x, &size_y);//�摜�T�C�Y���K��

	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	//DrawExtendGraphF(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//�摜���k���g��\��
	DrawRotaGraph3(pos_x + size_x/2, pos_y + size_y/2, size_x/2, size_y/2, scale_x, scale_y, rotate * DX_PI_F / 180, graphics, TRUE, graph_turn);//�摜���k���g��\��

	if (box_collision.BoxColliderMouse(pos_x * scale_x, size_x * scale_x, pos_y * scale_y, size_y * scale_y, wire) == true)//�R���W�����q�b�g����
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//�N���b�N����
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;

		click_flag = false;
	}

	if (click_flag == 1)//�N���b�N���ꂽ�Ƃ�wire�t���O��true��������O�����[�񃏃C���[��\��
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox((pos_x + double_line) * scale_x, (pos_y + double_line) * scale_y, (pos_x + (size_x - double_line)) * scale_x, (pos_y + (size_y - double_line)) * scale_y, GetColor(0, 255, 0), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���Bfor���͐��𑾂����鏈��)
			}
		}
	}

	SetDrawBright(255, 255, 255);//���̏��������Ȃ��Ɖ摜�\�����o�O��܂��B(��ʋP�x���ő�ɐݒ�)

	return click_flag;//�N���b�N����̌��ʂ�Ԃ��B
}

int ButtonUI:: BoxUI_WheelHorizontal(int pos_x, int pos_y, unsigned int color, bool wire)//�������ւ̃X���C�_�[
{
	GetGraphSize(graphics, &size_x, &size_y);//�摜�T�C�Y���K��

	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	DrawExtendGraphF(pos_x, pos_y, pos_x + size_x, pos_y + size_y, graphics, TRUE);//�摜���k���g��\��

	if ((pos_x + wheel_volume_buffer) <= pos_x)
	{
		wheel_volume_buffer = 0;
	}

	if ((pos_x + wheel_volume_buffer) >= pos_x + size_x)
	{
		wheel_volume_buffer = size_x;
	}

	DrawBox(pos_x + wheel_volume_buffer, pos_y, pos_x, pos_y + size_y, color, TRUE);

	if (box_collision.BoxColliderMouse(pos_x, size_x, pos_y, size_y, wire) == true)//�R���W�����q�b�g����
	{
		if (mouse_input.MouseClickContinuation(MOUSE_INPUT_LEFT) == 1)
		{
			GetMousePoint(&mouse_x, &mouse_y);
			wheel_volume_buffer = (mouse_x - pos_x);
		}
		red_a = 255;
		green_a = 255;
		blue_a = 255;
		click_flag = 1;
		wheel_volume = GetMouseWheelRotVol();
		wheel_volume_buffer += wheel_volume;
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
		click_flag = 0;
	}

	if (wheel_volume != 0)//�N���b�N���ꂽ�Ƃ�wire�t���O��true��������O�����[�񃏃C���[��\��
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox((pos_x + double_line), (pos_y + double_line), (pos_x + (size_x - double_line)), (pos_y + (size_y - double_line)), GetColor(0, 255, 0), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���Bfor���͐��𑾂����鏈��)
			}
		}
	}

	return click_flag;
}

int ButtonUI::BoxUI_WheelVertical(int pos_x, int pos_y, unsigned int color, bool wire)//�o�O����
{
	GetGraphSize(graphics, &size_x, &size_y);//�摜�T�C�Y���K��

	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	DrawExtendGraphF(pos_x, pos_y, pos_x + size_x, pos_y + size_y, graphics, TRUE);//�摜���k���g��\��

	if ((pos_y + size_y + wheel_volume_buffer) <= pos_y)
	{
		wheel_volume_buffer = size_y;
	}

	if ((pos_y + size_y + wheel_volume_buffer) >= pos_y + size_y)
	{
		wheel_volume_buffer = 0;
	}

	DrawBox(pos_x, pos_y + size_y + wheel_volume_buffer, pos_x, pos_y + size_y, color, TRUE);

	if (box_collision.BoxColliderMouse(pos_x, size_x, pos_y, size_y, wire) == true)//�R���W�����q�b�g����
	{
		if (mouse_input.MouseClickContinuation(MOUSE_INPUT_LEFT) == 1)
		{
			GetMousePoint(&mouse_x, &mouse_y);
			wheel_volume_buffer = (mouse_y - (pos_y));
		}
		red_a = 255;
		green_a = 255;
		blue_a = 255;
		click_flag = 1;
		wheel_volume = GetMouseWheelRotVol();
		wheel_volume_buffer -= wheel_volume;
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
		click_flag = 0;
		wheel_volume = 0;
	}

	if (wheel_volume != 0)//�N���b�N���ꂽ�Ƃ�wire�t���O��true��������O�����[�񃏃C���[��\��
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox((pos_x + double_line), (pos_y + double_line), (pos_x + (size_x - double_line)), (pos_y + (size_y - double_line)), GetColor(0, 255, 0), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���Bfor���͐��𑾂����鏈��)
			}
		}
	}

	return click_flag;
}

int ButtonUI::BoxUI_Button_Continuation(int pos_x, int pos_y, float scale_x, float scale_y, int input, bool wire)//�o�O�ɂ��X�P�[���̒l��1.0f�Ŏg�����ƁB�i�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B)
{
	GetGraphSize(graphics, &size_x, &size_y);//�摜�T�C�Y���K��

	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	DrawExtendGraphF(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//�摜���k���g��\��

	if (box_collision.BoxColliderMouse(pos_x, size_x * scale_x, pos_y, size_y * scale_y, wire) == true)//�R���W�����q�b�g����
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseClickContinuation(input);//�N���b�N����
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;

		click_flag = false;
	}

	if (click_flag == 1)//�N���b�N���ꂽ�Ƃ�wire�t���O��true��������O�����[�񃏃C���[��\��
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox(pos_x + double_line, pos_y + double_line, pos_x + (size_x - double_line), pos_y + (size_y - double_line), GetColor(0, 255, 0), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���Bfor���͐��𑾂����鏈��)
			}
		}
	}

	return click_flag;//�N���b�N����̌��ʂ�Ԃ��B
}

int ButtonUI::BoxUI_Button_Switch(int pos_x, int pos_y, float scale_x, float scale_y, int input, bool wire)//�o�O�ɂ��X�P�[���̒l��1.0f�Ŏg�����ƁB�i�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B�j
{
	GetGraphSize(graphics, &size_x, &size_y);//�摜�T�C�Y���K��

	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	DrawExtendGraphF(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//�摜���k���g��\��

	if (box_collision.BoxColliderMouse(pos_x, size_x * scale_x, pos_y, size_y * scale_y, wire) == true)//�R���W�����q�b�g����
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//�N���b�N����
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
	}

	if (click_flag == 1)//�N���b�N���ꂽ�Ƃ�wire�t���O��true��������O�����[�񃏃C���[��\��
	{
		switch_flag *= -1;
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox(pos_x + double_line, pos_y + double_line, pos_x + (size_x - double_line), pos_y + (size_y - double_line), GetColor(0, 255, 0), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���Bfor���͐��𑾂����鏈��)
			}
		}
	}

	if (switch_flag == 1)
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
	}

	//DrawFormatString(0, 0, GetColor(0, 0, 0), "sitch_flag = %d", switch_flag);

	return switch_flag;//�N���b�N����̌��ʂ�Ԃ��B
}

int ButtonUI::CircleUI_Button(int pos_x, int pos_y, int size_r, int input, bool wire)//(�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B�j
{
	GetGraphSize(graphics, &size_x, &size_y);//�摜�T�C�Y���K��

	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	DrawExtendGraphF(pos_x - (size_x/2), pos_y - (size_y/2), pos_x + (size_x / 2), pos_y + (size_y / 2), graphics, TRUE);//�摜���k���g��\��

	if (circle_collision.CircleColliderMouse(pos_x, pos_y, size_r, wire) == true)//�R���W�����q�b�g����
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//�N���b�N����
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;

		click_flag = false;
	}

	if (click_flag == 1)//�N���b�N���ꂽ�Ƃ�wire�t���O��true��������O�����[�񃏃C���[��\��
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawCircle(pos_x, pos_y, size_r - double_line, GetColor(0, 255, 0), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���Bfor���͐��𑾂����鏈��)
			}
		}
	}

	return click_flag;//�N���b�N����̌��ʂ�Ԃ��B
}

int ButtonUI::CircleUI_Button_Switch(int pos_x, int pos_y, int size_r, int input, bool wire)//�߂�l�̓N���b�N�t���O���Ԃ�B1�ŃN���b�N�A0�ŃN���b�N���Ă��Ȃ��B�j
{
	GetGraphSize(graphics, &size_x, &size_y);//�摜�T�C�Y���K��

	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	//DrawExtendGraph(pos_x - (size_x / 2), pos_y - (size_y / 2), pos_x + (size_x / 2), pos_y + (size_y / 2), graphics, TRUE);//�摜���k���g��\��

	if (circle_collision.CircleColliderMouse(pos_x, pos_y, size_r, wire) == true)//�R���W�����q�b�g����
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//�N���b�N����
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
	}

	if (click_flag == 1)//�N���b�N���ꂽ�Ƃ�wire�t���O��true��������O�����[�񃏃C���[��\��
	{
		switch_flag *= -1;
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawCircle(pos_x, pos_y, size_r - double_line, GetColor(0, 255, 0), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���Bfor���͐��𑾂����鏈��)
			}
		}
	}

	if (switch_flag == 1)
	{
		DrawExtendGraphF(pos_x - (size_x / 2), pos_y - (size_y / 2), pos_x + (size_x / 2), pos_y + (size_y / 2), graphics, TRUE);//�摜���k���g��\��
		red_a = 255;
		green_a = 255;
		blue_a = 255;
	}
	else
	{
		DrawExtendGraphF(pos_x - (size_x / 2), pos_y - (size_y / 2), pos_x + (size_x / 2), pos_y + (size_y / 2), switch_graphics, TRUE);//�摜���k���g��\��
		red_a = 200;
		green_a = 200;
		blue_a = 200;
	}

	//DrawFormatString(0, 0, GetColor(0, 0, 0), "sitch_flag = %d", switch_flag);

	return switch_flag;//�N���b�N����̌��ʂ�Ԃ��B
}