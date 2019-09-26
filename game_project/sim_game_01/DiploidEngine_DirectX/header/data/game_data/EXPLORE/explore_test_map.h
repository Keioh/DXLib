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

	//プレーヤー関連
	DiploidObject player_up;//プレーヤーの上
	DiploidObject player_down;//プレーヤーの下
	DiploidObject player_left;//プレーヤーの左
	DiploidObject player_right;//プレーヤーの右
	float player_size;
	float movement_speed = 5.0f;

public:
	Explore_TestMap() {};
	~Explore_TestMap() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

};