#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

class DiploidBox : public DiploidEngineObject
{
private:

public:
	VECTOR position_center;//�l�p�̒��S�_�̍��W

	void Init(VECTOR position, VECTOR size);//�}�E�X�ɒǏ]������ꍇ��{0,0,0}����
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };

};