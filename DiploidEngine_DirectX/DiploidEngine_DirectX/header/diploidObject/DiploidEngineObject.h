#pragma once
#include "DxLib.h"

class DiploidEngineObject
{
private:

public:
	VECTOR position;//�ʒu
	VECTOR size;//�傫��(z�͉~�̔��a)
	unsigned int color;//�F
	int fill;//�h��Ԃ�
	int thickness;//����

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};
};