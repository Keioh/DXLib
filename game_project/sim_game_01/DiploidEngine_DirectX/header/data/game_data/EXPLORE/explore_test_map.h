/*---------------------------------------------------------*/
/*--------------探索テストマップのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"
#include "diploid3D/diploidPanel.h"

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
	float movement_speed = 5.0f;//プレーヤーの移動速度


public:
	Explore_TestMap() {};
	~Explore_TestMap() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

};