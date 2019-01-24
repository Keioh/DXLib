#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidCircle : public DiploidEngineObjectInformation
{
private:
	VECTOR center_position;//オブジェクトの中心の値
	VECTOR anime_position;//アニメーションをするときの移動量を保存する変数。
	VECTOR anime_size;//アニメーションをするときのサイズを保存する変数。
	VECTOR origin_size;//元々の大きさ

	void DrawNameTag();

public:	

	DiploidCircle();
	~DiploidCircle();

	void Init(VECTOR position, float size);
	void Update();
	void Draw(bool wire = true);

	float GetSize();//円の大きさを返します。
	VECTOR GetCenterPosition();//中央の位置を返します。

	void Destory() { impacted = destory = true; };

	int SetDrawNameTagFlag(int flag = TRUE);//TRUEでname_tagを表示。

};