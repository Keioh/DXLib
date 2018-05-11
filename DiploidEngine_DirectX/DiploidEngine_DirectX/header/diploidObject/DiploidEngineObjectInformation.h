#pragma once
#include "DxLib.h"

class DiploidEngineObjectInformation
{
private:

public:
	int name_tag;//enum NAME�œo�^�������̂���

	bool mouse_point_move_flag = false;
	VECTOR position;//�ʒu
	VECTOR size;//�傫��(z�͉~�̔��a)	
	int mouse_position_x, mouse_position_y;
	unsigned int color;//�F
	int fill;//�h��Ԃ�
	int thickness;//����

	//���ۂɓ������Ƃ��ɕύX����ϐ�
	VECTOR move_speed;
	VECTOR move_size;

	//Impact�������ǂ����̃t���O
	bool impacted = false;
	bool destory = false;

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};

	virtual void Destory() { impacted = destory = true; };
};