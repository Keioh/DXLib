#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

//Impact������UI�ɂ̂ݎg�p
class DiploidBox : public DiploidEngineObjectInformation
{
private:

public:
	VECTOR center_position;//�l�p�̒��S�_�̍��W

	void Init(VECTOR position, VECTOR size);//�}�E�X�ɒǏ]������ꍇ��{0,0,0}����
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };
};