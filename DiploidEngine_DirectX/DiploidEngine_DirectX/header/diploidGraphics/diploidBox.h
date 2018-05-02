#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

//Impact処理はUIにのみ使用
class DiploidBox : public DiploidEngineObject
{
private:

public:
	VECTOR center_position;//四角の中心点の座標

	void Init(VECTOR position, VECTOR size);//マウスに追従させる場合は{0,0,0}を代入
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };
};