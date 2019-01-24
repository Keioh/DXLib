#pragma once
#include <math.h>
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

//現状サイズ変更関数は未実装
class DiploidLine : public DiploidEngineObjectInformation
{
private:
	VECTOR POSITION_ONE, POSITION_TWO;

	VECTOR anime_position_one, anime_position_two;//アニメーションをするときの移動量を保存する変数。
	VECTOR anime_size;//アニメーションをするときのサイズを保存する変数。
	VECTOR origin_size;//元々の大きさ

	void DrawNameTag();

public:

	VECTOR Position_one, Position_two;

	void Init(VECTOR position_one, VECTOR position_two);
	void Update();
	void Draw(bool wire = false);

	void Destory() { impacted = destory = true; };

	double GetAngle();//線分の傾きを取得

	int SetDrawNameTagFlag(int flag = TRUE);//TRUEでname_tagを表示。

};