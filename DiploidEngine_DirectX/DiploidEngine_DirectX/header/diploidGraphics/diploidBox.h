#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

class DiploidBox : public DiploidEngineObject
{
private:

public:

	void Init(VECTOR position);//�}�E�X�ɒǏ]������ꍇ��{0,0,0}����
	void Update();
	void Draw(bool wire = true);

};