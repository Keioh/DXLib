#pragma once
#include "DxLib.h"
#include "ObjectVector.h"
#include "define.h"

//オブジェクトを作る際の基本になる記述
class ObjectBase
{

private:

public:
	~ObjectBase(){};		//デストラクタ

	//intポジション
	int x;
	int y;
	int z;

	//intサイズ
	int size_x;
	int size_y;
	int size_z;

	//intα値
	int red_a;
	int green_a;
	int blue_a;

	//floatポジション
	float xF;
	float yF;
	float zF;


};	

struct SEQUENCE
{
	int title_screen;
	int game_screen;
	int load_screen;
	int option_screen;
	int exit_screen;
};