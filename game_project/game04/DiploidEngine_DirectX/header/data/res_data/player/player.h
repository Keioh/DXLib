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
	float attack_speed = 8.0f;//攻撃速度
	float defense_speed = 3.0f;//防御速度
	float attack_range = 45.0f;//攻撃距離
	float attack_size = 30.0f;//攻撃の大きさ
	float defense_size = 70.0f;//防御の大きさ
	int enemy_destory_volume = 0.0f;//敵撃破数
	float hp_recovery_probability = 0.0f;//敵を撃破した際にHPが回復する確率。
	float cp_recovery_probability = 0.0f;//設定した敵撃破数に達成したらCPを回復する。


	//Player本体
	DiploidCircleV2 player;
	VECTOR player_pos;
	float player_size = 35.0f;//プレイヤーの当たり判定の大きさ
	float hp_probability_buffer = 0.0f;//確率を保存
	float cp_probability_buffer = 0.0f;//確率を保存
	bool enemy_destory_flag_bffer;//enemy_managerからのデストロイフラグの保存用

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

	void HpRecoveryProbabilityUpdate();
	void CpRecoveryProbabilityUpdate();

	void SetPlayerSize(float new_size);
	void isEnemyDestoryVolume(float destory_enemy_volume);//敵が倒されたときに1足される
	void isGetEnemyDestroyFlag(bool destory_enemy_flag);

	float GetPlayerSize();
	float GetPlayerDefensePoint();
	float GetEnemyDestoryVolume();
	float GetHpRecoveryProbability();
	float GetCpRecoveryProbability();

	void SetAttackSpeed(float new_vol);
	void AddAttackSpeed(float add_vol);//ASに足す
	void AddHpRecoveryProbability(float add_vol);//HP回復確率に足す
	void AddCpRecoveryProbability(float add_vol);//CP回復確率に足す

	DiploidCircleV2* PlayerCirclePtr();

	std::list<PlayerAttack>* GetAttackListPtr();//<list>attack_listへのpointerを取得します。
	std::list<PlayerDefense>* GetDefenseListPtr();//<list>defense_listへのpointerを取得します。

	std::list<PlayerAttack>::iterator GetAttackListIterator();//<list>attack_listのイテレータを取得します。
	std::list<PlayerDefense>::iterator GetDefenseListIterator();//<list>defense_listのイテレータを取得します。

};