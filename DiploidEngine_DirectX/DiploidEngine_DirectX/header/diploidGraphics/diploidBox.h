#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

class DiploidBox : public DiploidEngineObject
{
private:

public:

	void Init(VECTOR position);//マウスに追従させる場合は{0,0,0}を代入
	void Update();
	void Draw(bool wire = true);

};