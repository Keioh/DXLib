#include "Dice.h"

DICE::DICE()
{
	font_size = 50;
	font_thick = 4;

	oneDhundred = 50;

	critical_init = 5;
	fumble_init = 95;

	graph_drawing_flag = 1;
}

void DICE::init()
{
	font_handl = CreateFontToHandle(NULL, font_size, font_thick, DX_FONTTYPE_ANTIALIASING_8X8);//�V�����t�H���g�Z�b�g�����B
}

void DICE::Load()
{
	graph_1D100 = LoadGraph("pack/ui/1d100.png");
	graph_1D100_hit = LoadGraph("pack/ui/1d100_hit.png");
	graph_critical = LoadGraph("pack/ui/critical.png");
	graph_fumble = LoadGraph("pack/ui/fumble.png");

}

int DICE::Dice_role_oneDhundred(int x, int y)
{		

	GetMousePoint(&mouse_x, &mouse_y);//�}�E�X�J�[�\���ʒu���K��

	DrawGraph(x, y, graph_1D100, TRUE);

	if (x < mouse_x && y < mouse_y)//�J�[�\���������̓����Ȃ�
	{
		if (x + 100 > mouse_x && y + 50 > mouse_y)
		{	
			seed_count += GetRand(100) + 1;//seed��ς���

			DrawGraph(x, y, graph_1D100_hit, TRUE);

			if ((oneD100_click = Mouse_Cilck(MOUSE_INPUT_LEFT, 0)) == true)//�u�ԃN���b�N����Ɠ����ɕϐ��փN���b�N�������
			{
				SRand(seed_count);
				oneDhundred = GetRand(100);//0~100�̗������擾
				graph_drawing_flag = 1;//�N���t�@���摜�\���t���O���I���ɂ���
				seed_count = 0;
			}
		}
	}

	if (oneDhundred <= 0)oneDhundred = 1;//�_�C�X���[���̌��ʂ�0�ȉ���������1�ɂ���B

	DrawFormatStringToHandle(x + 24, y, GetColor(0, 0, 0), font_handl, "%d", oneDhundred);//���ʂ�`��

	return oneDhundred;
}

int DICE::Dice_role_custom(int x, int y)
{
	DrawBox(x, y, x + 50, y + 50, GetColor(150, 150, 150), TRUE);
	DrawBox(x + 70, y, x + 120, y + 50, GetColor(150, 150, 150), TRUE);
	DrawBox(x + 120, y, x + 170, y + 50, GetColor(150, 150, 150), TRUE);

	if (start > 10)start = 10;
	if (start <= 0)start = 1;
	if (end > 10)end = 10;
	if (end <= 0)end = 1;

	//?D?�̍ŏ���?�̕���
	if (x < mouse_x && y < mouse_y)//�J�[�\���������̓����Ȃ�
	{
		if (x + 50 > mouse_x && y + 50 > mouse_y)
		{
			DrawBox(x, y, x + 50, y + 50, GetColor(200, 200, 200), TRUE);
			start += GetMouseWheelRotVol();//�}�E�X�̉�]�ʂ𓾂�
		}
	}

	//?D?�̍Ō��?�̕���
	if (x + 70 < mouse_x && y < mouse_y)//�J�[�\���������̓����Ȃ�
	{
		if (x + 120 > mouse_x && y + 50 > mouse_y)
		{
			DrawBox(x + 70, y, x + 120, y + 50, GetColor(200, 200, 200), TRUE);
			end += GetMouseWheelRotVol();//�}�E�X�̉�]�ʂ𓾂�
		}
	}

	//?D?�̌��ʕ\���{�^���̕���
	if (x + 120 < mouse_x && y < mouse_y)//�J�[�\���������̓����Ȃ�
	{
		if (x + 170 > mouse_x && y + 50 > mouse_y)
		{
			DrawBox(x + 120, y, x + 170, y + 50, GetColor(200, 200, 200), TRUE);
			seed_count += GetRand(100) + 1;//seed��ς���

			if ((Mouse_Cilck(MOUSE_INPUT_LEFT, 0)) == true)//�u�ԃN���b�N����Ɠ����ɕϐ��փN���b�N�������
			{
				SRand(seed_count);
				customDcustom = GetRand(start * end);//start��end���|�����������擾
				graph_drawing_flag = 1;//�N���t�@���摜�\���t���O���I���ɂ���
				seed_count = 0;

			}
		}
	}

	if (customDcustom <= 0)customDcustom = 1;

	DrawFormatStringToHandle(x + 5, y, GetColor(0, 0, 0), font_handl, "%d", start);//�ŏ��̃_�C�X
	DrawFormatStringToHandle(x + 75, y, GetColor(0, 0, 0), font_handl, "%d", end);//�Ō�̃_�C�X
	DrawFormatStringToHandle(x + 170, y, GetColor(0, 0, 0), font_handl, "%d", customDcustom);//���ʂ̕\��


	return customDcustom;
}

void DICE::Critical_Fumble_Screen()
{
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) graph_drawing_flag = 0;//�E�N���b�N������N���t�@���摜�̕\�����I�t�ɂ���B

	if (graph_drawing_flag == 1)
	{
		if (oneDhundred < critical_init)DrawGraph(0, 0, graph_critical, TRUE);
		if (oneDhundred > fumble_init)DrawGraph(0, 0, graph_fumble, TRUE);
	}
}