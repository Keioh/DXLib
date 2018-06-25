#pragma once
#include "DxLib.h"

class DiploidEngineObjectInformation
{
private:

public:
	int name_tag;//enum NAMEで登録したものを代入

	bool mouse_point_move_flag = false;
	VECTOR position;//位置
	VECTOR size;//大きさ(zは円の半径)	
	int mouse_position_x, mouse_position_y;
	unsigned int color;//色
	int fill;//塗りつぶし
	int thickness;//太さ

	//実際に動かすときに変更する変数
	VECTOR move_speed;
	VECTOR move_size;

	//Impactしたかどうかのフラグ
	bool impacted = false;
	bool destory = false;

	unsigned int number;//VisualStudioの場合、4Byte(0～4294967295)までのオブジェクト番号を登録可能

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};

	virtual void Destory() { impacted = destory = true; };
};