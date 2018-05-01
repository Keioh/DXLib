#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

class DiploidBox : public DiploidEngineObject
{
private:

public:
	VECTOR position_center;//四角の中心点の座標

	void Init(VECTOR position, VECTOR size);//マウスに追従させる場合は{0,0,0}を代入
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };

};