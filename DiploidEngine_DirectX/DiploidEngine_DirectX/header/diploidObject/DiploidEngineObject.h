#pragma once
#include "DxLib.h"

class DiploidEngineObject
{
private:

public:
	bool mouse_point_move_flag = false;
	VECTOR position;//�ʒu
	VECTOR size;//�傫��(z�͉~�̔��a)	
	int mouse_position_x, mouse_position_y;
	unsigned int color;//�F
	int fill;//�h��Ԃ�
	int thickness;//����

	VECTOR move_speed;
	float move_size;

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};
};