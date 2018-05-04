#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

//Impact処理はUIにのみ使用
class DiploidBox : public DiploidEngineObjectInformation
{
private:

public:
	VECTOR center_position;//四角の中心点の座標
	VECTOR anime_position, anime_size;//
	VECTOR origin_position, origin_size;//
	int mouse_x, mouse_y;

	void Init(VECTOR position, VECTOR size);//マウスに追従させる場合は{0,0,0}を代入
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };
};