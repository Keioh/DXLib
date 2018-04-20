#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

class DiploidPoint : public DiploidEngineObject
{
private:
	VECTOR center_position;//オブジェクトの中心の値

public:
	VECTOR anime_position;//アニメーションをするときの移動量を保存する変数。

	void Init(VECTOR position);//マウスに追従させる場合は{0,0,0}を代入
	void Update(VECTOR move_speed, bool mouse_point = false);
	void Draw(bool wire = true);
};