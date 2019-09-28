/*---------------------------------------------------------*/
/*--------------プレーヤーの画像処理がここに---------------*/
/*------------PLの移動処理はテストマップに記載-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"

class PlayerDirection
{
private:

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
	float player_scale;//プレーヤーの大きさ保存用(player_sizeの保存用)
	float player_size;//プレーヤーの大きさ(map_chip_sizeの0.2倍)
	float movement_speed = 5.0f;//プレーヤーの移動速度


public:

	void Load();
	void Init(float player_scale);
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

	int GetDirection();//現在向いている方向を得ます。
};