#pragma once
#include <string>
#include "DxLib.h"

//#include "data/system_data/system_data.h"

struct SystemData
{
	//����̐ݒ�
	std::string language;//����

	//Window�ݒ�֘A
	int window_x;//���ۂ̃E�B���h�E�T�C�Y(��)
	int window_y;//���ۂ̃E�B���h�E�T�C�Y(��)
	int simulation_window_x;//�V�~�����[�g�̃E�B���h�E�T�C�Y(��)
	int simulation_window_y;//�V�~�����[�g�̃E�B���h�E�T�C�Y(��)
	int refreshrate;//���t���b�V�����[�g
	bool window_mode;//�t���X�N���[����
	bool vsync;//����������҂�

	bool shadow_map;//�V���h�E�}�b�v��\�����邩

	int shadow_map_size_x;//�V���h�E�}�b�v�̑傫��(x)
	int shadow_map_size_y;//�V���h�E�}�b�v�̑傫��(y)

	float shadow_map_min_area_x;//�V���h�E�}�b�v�̍ŏ��`��͈�
	float shadow_map_min_area_y;
	float shadow_map_min_area_z;

	float shadow_map_max_area_x;//�V���h�E�}�b�v�̍ő�`��͈�
	float shadow_map_max_area_y;
	float shadow_map_max_area_z;


	//�����`��ݒ�֘A
	float string_draw_speed;//�����̕`�摬�x
	float string_auto_speed;//�����̃I�[�g���x
	float string_background_alpha;//�����̔w�i���ߓx
};