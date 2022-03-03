#pragma once
#include "DxLib.h"
#include "data/sim_data/fild.h"

class FildMap
{
private:
	float scale = 0.05f;//マップチップの初期の大きさ

	float mouse_scrole;//マウススクロール量の保存
	int mouse_x, mouse_y;

	float camera_x, camera_y, camera_speed = 30.0f;//カメラの位置と移動スピード
	VECTOR map_shift;//初期化時にどれくらいマップをずらして表示するか

	int click_flag = -1;

	//画像
	DiploidImageV2 	grass_terrain, rock_terrain, mountain_terrain, my_building;

	Fild fild[MAP_SIZE_Y][MAP_SIZE_X];//マップの大きさ分だけfildチップを確保

	void CameraInput(DiploidEngineInput* input);//カメラの設定(カメラの移動速度とか)

public:
	void LoadHandl();
	void LoadGraphics();
	void Load();

	void Init(VECTOR position = { 0.0f,0.0f,0.0f }, float map_size_scale = 0.05f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	void SetCollisionActiveFlag(bool flag);//指定した場所のマップの当たり判定アクティブフラグを設定します。

	int GetClick();//現在マップのどれかがクリックされているか。

	Fild GetClickedFildInfomation();//クリックされている場所のデータを取得。
	Fild GetHitFildInfomation();//ヒットしている場所のデータを取得。

};