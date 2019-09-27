/*---------------------------------------------------------*/
/*--------------探索パートのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"
#include "diploid3D/diploidPanel.h"

class Explore_TestMap
{
private:
	//マップ関連
	DiploidObject test_map;//マップ作製用
	DiploidObject test_map_texter;//マップテクスチャ用
	VECTOR map_position;//マップの位置
	VECTOR map_center_position_sub;//マップのズレ差
	VECTOR map_size;//マップの大きさ
	float map_chip_size;//マップチップの大きさ
	float map_image_x, map_image_y;//マップ画像の大きさ
	int map_number;//name_tagの番号

	void _MapLoad();
	void _MapInit(VECTOR position);
	void _MapPush(DiploidEngineImpact* impact);
	void _MapUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input);
	void _MapDraw(bool draw = true);

	//プレーヤー関連
	DiploidObject player_up;//プレーヤーの上の当たり判定
	DiploidObject player_down;//プレーヤーの下の当たり判定
	DiploidObject player_left;//プレーヤーの左の当たり判定
	DiploidObject player_right;//プレーヤーの右の当たり判定

	DiploidObject player_up_image;//プレーヤーの上の画像
	DiploidObject player_down_image;//プレーヤーの下の画像
	DiploidObject player_left_image;//プレーヤーの左の画像
	DiploidObject player_right_image;//プレーヤーの右の画像

	DiploidObject player_left_up_image;//プレーヤーの左上の画像
	DiploidObject player_right_up_image;//プレーヤーの右上の画像
	DiploidObject player_left_down_image;//プレーヤーの左下の画像
	DiploidObject player_right_down_image;//プレーヤーの右下の画像

	int player_direction = PLAYER_DOWN;//プレーヤーの向き
	float player_size;//プレーヤーの大きさ(map_chip_sizeの0.2倍)
	float movement_speed = 5.0f;//プレーヤーの移動速度

	void _PlayerLoad();
	void _PlayerInit();
	void _PlayerPush(DiploidEngineImpact* impact);
	void _PlayerUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input);
	void _PlayerDraw(bool draw = true);


public:
	Explore_TestMap() {};
	~Explore_TestMap() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

};