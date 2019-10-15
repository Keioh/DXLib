/*---------------------------------------------------------*/
/*--------------探索テストマップのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidSystem/diploidSystem.h"
#include "diploidUI/diploidUI.h"

#include "data/game_data/UI/command_ui.h"
#include "data/game_data/UI/status_bar.h"
#include "data/game_data/UI/clock.h"

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
	void _MapUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input, CommandUI* command_ui, StatusBar* status_bar, Clock* clock);
	void _MapDraw(bool draw = true);

	//プレーヤー関連	
	DiploidObject player_visibility;//視界画像
	PlayerDirection player_direction;//プレーヤー表示
	float player_size;//プレーヤーの大きさ(map_chip_sizeの0.2倍)

	float movement_speed = 3.0f;//プレーヤーの移動速度
	float movement_run_scale = 1.8f;//走る際の移動倍率

	int movement_type = PLAYER_WAIT;//プレーヤーの移動状態


	//敵関連
	DiploidObject enemy_test;//敵の当たり判定

	VECTOR enemy_position;
	bool enemy_dead = false;
	bool enemy_hit = false;

	//戦闘画面
	DiploidSystem system;//ワンショット読み込み用

	DiploidObject combat_back_texter;//戦闘画面の背景
	DiploidObject mouse_point;//戦闘画面用のマウスポイント

	DiploidUI battle_command;//戦闘コマンド

public:
	Explore_TestMap() {};
	~Explore_TestMap() {};


	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input, CommandUI& command_ui, StatusBar& status_bar, Clock& clock);
	void Draw(bool draw = true);

	bool GetEnemyHitFlag();

};