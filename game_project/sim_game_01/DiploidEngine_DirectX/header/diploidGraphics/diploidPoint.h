#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidPoint : public DiploidEngineObjectInformation
{
private:
	VECTOR center_position;//オブジェクトの中心の値

public:
	VECTOR anime_position;//アニメーションをするときの移動量を保存する変数。

	void Init(VECTOR position);//マウスに追従させる場合は{0,0,0}を代入
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };

	std::string GetNameTag();//name_tagに設定されている名前を返します。

};