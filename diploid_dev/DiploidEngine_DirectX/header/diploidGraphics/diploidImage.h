#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidImage : public DiploidEngineObjectInformation
{
private:
	VECTOR anime_position;
	VECTOR origin_position;
	VECTOR center_position;
	double anime_size;
	double move_size_private;	
	double anime_angle;
	double origin_angle;
	double origin_size;//z軸を使用

	void DrawNameTag();

public:
	int handl = DX_NONE_GRAPH;
	int mouse_x, mouse_y;
	double scale = 1.0f;
	double angle = 0.0f;
	float blend_volume = 255;
	float blend_speed = 0;
	int blend_mode = DX_BLENDMODE_ALPHA;
	int revers_x = FALSE;
	int revers_y = FALSE;
	int GRAPHICS_SIZE_X, GRAPHICS_SIZE_Y;//他の数値を入れる前にコピーを取っておかないと数値が消える。
	int red_bright = 255;
	int green_bright = 255;
	int blue_bright = 255;//画像の明るさ
	float red_bright_speed = 0.0f;
	float green_bright_speed = 0.0f;
	float blue_bright_speed = 0.0f;
	double move_angle;



	void Load(const char* path);//画像読み込み
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, double size_scale = 1.0f, double angle_scale = 0.0f);//初期位置(size_scaleは1で等倍、2で二倍など)
	void Updata();//位置やアニメーションなどの更新(つまり主に座標移動)
	void Draw(bool draw = true);//画像を表示

	int GetGraphicsSizeX();//読み込んだ画像のXの大きさを取得します。
	int GetGraphicsSizeY();//読み込んだ画像のYの大きさを取得します。

	void TransformScale(float scale = 1.0f);//サイズスケールを変更する。

	int SetDrawNameTagFlag(int flag = FALSE);//TRUEでname_tagを表示。
	std::string GetNameTag();//name_tagに設定されている名前を返します。

};