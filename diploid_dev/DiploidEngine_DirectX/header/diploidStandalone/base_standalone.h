#pragma once
#include "DxLib.h"
//スタンドアローン基底クラス

class BaseStandalone
{
private:

public:
	BaseStandalone();
	~BaseStandalone();

	VECTOR size;		//オブジェクトの大きさ
	VECTOR position;	//オブジェクトの位置
	float radius;		//オブジェクトの半径
	float scale = 1.0f;		//現在のスケール値(1.0fで等倍)

	bool hit = false;	//オブジェクトが他のオブジェクトに当たっているかどうか(trueの場合、当たっている)

};