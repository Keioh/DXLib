#pragma once
#include "DxLib.h"
#include "System.h"

class DICE
{
private:
	int font_size;//�t�H���g�̑傫��
	int font_thick;//�t�H���g�̑���
	int font_handl;//�t�H���g�n���h��

	int critical_init;//�N���e�B�J���̔��萔�̌���
	int fumble_init;//�t�@���u���̔��萔�̌���

	int graph_1D100;
	int graph_1D100_hit;
	int graph_critical;
	int graph_fumble;

	int mouse_x, mouse_y;//�}�E�X�J�[�\���̈ʒu

public:
	DICE();
	int seed_count;//rand�V�[�h�̕ύX�ϐ�
	int oneDhundred;//1d100�̌��ʂ�ۑ�����ϐ��B
	int customDcustom;//?d?�̌��ʂ�ۑ�����ϐ��B
	int start;
	int end;

	bool oneD100_click;//1d100�����������ǂ����̃t���O
	int graph_drawing_flag;//�N���t�@���摜��\�����邩�ǂ����̃t���O

	void init();
	void Load();

	int Dice_role_oneDhundred(int x, int y);//1d100�̃_�C�X���[��
	int Dice_role_custom(int x, int y);//?d?�̃_�C�X���[��

	void Critical_Fumble_Screen();//�N���ƃt�@���O���̉摜�\���Ɣ���B
};