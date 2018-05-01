#pragma once
#include "DxLib.h"

class DiploidEngineObject
{
private:

public:
	bool mouse_point_move_flag = false;
	VECTOR position;//位置
	VECTOR size;//大きさ(zは円の半径)	
	int mouse_position_x, mouse_position_y;
	unsigned int color;//色
	int fill;//塗りつぶし
	int thickness;//太さ

	//実際に動かすときに変更する変数
	VECTOR move_speed;
	float move_size;

	//Impactしたかどうかのフラグ
	bool impacted = false;
	bool destory = false;

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};

	virtual void Destory() { impacted = destory = true; };
};