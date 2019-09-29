/*---------------------------------------------------------*/
/*--------------探索テストマップのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidSystem/diploidSystem.h"

#include "data/game_data/CHARACTER/player_direction.h"


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
	PlayerDirection player_direction;//プレーヤー表示
	float player_size;//プレーヤーの大きさ(map_chip_sizeの0.2倍)

	float movement_speed = 3.0f;//プレーヤーの移動速度
	float movement_run_scale = 1.8f;//走る際の移動倍率
	float rinjury_lv1_scale = 0.8f;//怪我を負った際のLV1倍率
	float rinjury_lv2_scale = 0.6f;//怪我を負った際のLV2倍率
	float rinjury_lv3_scale = 0.5f;//怪我を負った際のLV3倍率
	float rinjury_lv4_scale = 0.3f;//怪我を負った際のLV4倍率
	float rinjury_lv5_scale = 0.1f;//怪我を負った際のLV5倍率

	int movement_type = PLAYER_WALK;//プレーヤーの移動状態

public:
	Explore_TestMap() {};
	~Explore_TestMap() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

};