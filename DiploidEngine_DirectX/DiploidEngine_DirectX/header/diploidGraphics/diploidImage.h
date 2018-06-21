#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidImage : public DiploidEngineObjectInformation
{
private:

public:
	int handl;
	int mouse_x, mouse_y;
	double scale = 1.0f;
	double angle = 0.0f;
	float blend_volume = 255;
	float blend_speed = 0;
	int blend_mode = DX_BLENDMODE_ALPHA;
	int revers_x = FALSE;
	int revers_y = FALSE;
	int GRAPHICS_SIZE_X, GRAPHICS_SIZE_Y;

	bool destory = false;

	VECTOR anime_position;
	VECTOR origin_position;
	VECTOR center_position;
	double anime_size;
	double move_size;	
	double move_angle;
	double anime_angle;
	double origin_angle;
	double origin_size;//z軸を使用


	void Load(const char* path);//画像読み込み
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, double size_scale = 1.0f, double angle_scale = 0.0f);//初期位置(size_scaleは1で等倍、2で二倍など)
	void Updata();//位置やアニメーションなどの更新(つまり主に座標移動)
	void Draw(bool draw = true);//画像を表示
};