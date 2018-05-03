#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidCircle : public DiploidEngineObjectInformation
{
private:
	VECTOR center_position;//オブジェクトの中心の値

public:		
	VECTOR anime_position;//アニメーションをするときの移動量を保存する変数。
	float anime_size;//アニメーションをするときのサイズを保存する変数。
	float origin_size;//元々の大きさ

	void Init(VECTOR position, float size);
	void Update();
	void Draw(bool wire = true);

	void Destory() { impacted = destory = true; };
};