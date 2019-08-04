#pragma once
#include <string>
#include "DxLib.h"

class DiploidEngineObjectInformation
{
private:

public:
	std::string name_tag = "no_name";//�t���������O������B�^��string�^�ł��B

	bool mouse_point_move_flag = false;//true�ɂ���ƃ}�E�X�ɒǏ]
	bool center_position_draw_flag = false;//true�ɂ���ƒ����ɐݒ肳��Ă���ꏊ�ɓ_���\�������(�}�E�X�Ǐ]�̏ꍇ�͖���)
	VECTOR position;//�ʒu
	VECTOR size;//�傫��(z�͉~�̔��a)	
	int mouse_position_x, mouse_position_y;//�}�E�X�̌��݂̈ʒu
	unsigned int color;//�F
	int fill;//�h��Ԃ�
	int thickness;//����

	//���ۂɓ������Ƃ��ɕύX����ϐ�
	VECTOR move_speed;//�ړ����x
	VECTOR move_size;//�傫���ύX

	//Impact�������ǂ����̃t���O
	bool impacted = false;//true�œ������Ă���
	bool destory = false;//true�ō폜

	int name_tag_flag;//name_tag�̕\���t���O


	//��)1-29�@���@���ʔԍ� - �I�u�W�F�N�g�ԍ�
	//���ʔԍ���UI�Ȃ̂��Q�[���I�u�W�F�N�g�Ȃ̂��Ȃǂ𔻕ʂ��邽�߂̕ϐ��B
	//���ʔԍ��̒��ŉ��ڂ̃I�u�W�F�N�g�Ȃ̂��̔��ʂ��邽�߂̕ϐ��B
	int number;//�I�u�W�F�N�g�ԍ�(�ԍ��͂Ȃ�ׂ����Ԃ�Ȃ��悤��)
	int layer_number;//���ʔԍ�

	//���ǉ�(�G���[���o��ꍇ�͍폜)
	DiploidEngineObjectInformation();//�R���X�g���N�^
	~DiploidEngineObjectInformation();//�f�X�g���N�^

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};

	virtual void Destory() { impacted = destory = true; };//�I�u�W�F�N�g�폜�֐�
};