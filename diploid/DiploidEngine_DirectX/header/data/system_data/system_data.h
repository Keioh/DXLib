#pragma once
#include "DxLib.h"

//#include "data/system_data/system_data.h"

struct SystemData
{
	//Window�ݒ�֘A
	int window_x;//���ۂ̃E�B���h�E�T�C�Y(��)
	int window_y;//���ۂ̃E�B���h�E�T�C�Y(��)
	int simulation_window_x;//�V�~�����[�g�̃E�B���h�E�T�C�Y(��)
	int simulation_window_y;//�V�~�����[�g�̃E�B���h�E�T�C�Y(��)
	int refreshrate;//���t���b�V�����[�g
	bool window_mode;//�t���X�N���[����
	bool vsync;//����������҂�

	//�����`��ݒ�֘A
	float string_draw_speed;//�����̕`�摬�x
	float string_auto_speed;//�����̃I�[�g���x
	float string_background_alpha;//�����̔w�i���ߓx
};