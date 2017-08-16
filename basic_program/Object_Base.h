#pragma once
#include "DxLib.h"

//オブジェクトを作る際の基本になる記述
class ObjectBase
{

private:

public:
	ObjectBase();		//コンストラクタ
	~ObjectBase(){};		//デストラクタ

	//intポジション
	int x;
	int y;
	int z;

	//intサイズ
	int size_x;
	int size_y;
	int size_z;

	//floatポジション
	float xF;
	float yF;
	float zF;

};