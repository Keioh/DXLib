#include "button_ui.h"


ButtonUI::ButtonUI()
{

}

int ButtonUI::Load(char* path)
{
	graphics = LoadGraph(path);
	GetGraphSize(graphics, &size_x, &size_y);//1�摜�T�C�Y���K��

	return graphics;//�O���t�B�b�N�n���h����Ԃ��B
}

int ButtonUI::BoxUI_Button(int pos_x, int pos_y, float scale_x, float scale_y, int input, bool wire)
{
	SetDrawBright(red_a, green_a, blue_a);//�q�b�g���Ă���ꍇ�A�摜�̋P�x��255�ɂ���B(�q�b�g���Ă��Ȃ��ꍇ��200)
	DrawExtendGraph(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//�摜���k���g��\��

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
