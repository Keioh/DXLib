#pragma once
#include "DxLib.h"

class EnemyData
{
private:

public:
	VECTOR pos;//位置
	float size;//大きさ
	float move_speed;//移動速度
	float attack_speed;//攻撃速度
	int hit_point;//体力
	float attack_size;//攻撃の範囲
	float attack_renge;//攻撃の距離
	float counter_time;//カウンター受付可能な時間
	float knock_back_scale;//ノックバック倍率
	int enemy_type;//敵の種類(画像が変わる)
	int direction;//向いている方向(0で右、1で左)
	bool is_ground;//地面に着いているか
	float scale;
};