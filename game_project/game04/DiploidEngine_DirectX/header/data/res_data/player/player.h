#pragma once
#include <list>
#include "math.h"
#include "DxLib.h"

#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "diploidInput/DiploidEngineInput.h"

#include "data/res_data/anime/animation.h"

#include "data/res_data/player/player_attack.h"
#include "data/res_data/player/player_defense.h"

class Player
{
private:
	//Playerのステータス
	float hit_point = 3.0f;//体力
	float defense_point = 3.0f;//防御可能数(カウンター)
	float attack_speed = 3.0f;//攻撃速度
	float defense_speed = 3.0f;//防御速度
	float attack_range = 45.0f;//攻撃距離
	float attack_size = 30.0f;//攻撃の大きさ
	float defense_size = 70.0f;//防御の大きさ
	float enemy_destory_volume = 0.0f;

	//Player本体
	DiploidCircleV2 player;
	VECTOR player_pos;
	float player_size = 35.0f;//プレイヤーの当たり判定の大きさ

	//Playerの攻撃
	std::list<PlayerAttack> attack_list;
	PlayerAttack attack;
	VECTOR attack_pos;//実際の攻撃位置
	float attack_rote;//マウスとPlayer間の角度
	bool is_attack = false;//攻撃中かどうか

	//Playerの防御
	PlayerDefense defense;
	std::list<PlayerDefense> defense_list;
	bool is_defense = false;//防御中かどうか

	//攻撃アニメーション
	DiploidImageV2 attack_image;
	Animation attack_anime;

	//防御アニメーション
	DiploidImageV2 defense_image;
	Animation defense_anime;

	//入力
	DiploidEngineInput input_left;
	DiploidEngineInput input_right;

public:
	void LoadGraphics();

	void Init(VECTOR pos);
	void Updata();
	void Draw(bool debug = false, bool draw = true);

	void SetPlayerSize(float new_size);
	void isEnemyDestoryHelthRecovery(float destory_enemy_volume);//敵が倒されたときに1足される

	float GetPlayerSize();
	float GetPlayerDefensePoint();
	float GetEnemyDestoryVolume();

	DiploidCircleV2* PlayerCirclePtr();

	std::list<PlayerAttack>* GetAttackListPtr();//<list>attack_listへのpointerを取得します。
	std::list<PlayerDefense>* GetDefenseListPtr();//<list>defense_listへのpointerを取得します。

	std::list<PlayerAttack>::iterator GetAttackListIterator();//<list>attack_listのイテレータを取得します。
	std::list<PlayerDefense>::iterator GetDefenseListIterator();//<list>defense_listのイテレータを取得します。

};