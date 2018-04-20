#pragma once
#include "DxLib.h"

class DiploidEngineObject
{
private:

public:
	int mouse_position_x, mouse_position_y;
	VECTOR position;//�ʒu
	VECTOR size;//�傫��(z�͉~�̔��a)
	unsigned int color;//�F
	int fill;//�h��Ԃ�
	int thickness;//����

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};
};