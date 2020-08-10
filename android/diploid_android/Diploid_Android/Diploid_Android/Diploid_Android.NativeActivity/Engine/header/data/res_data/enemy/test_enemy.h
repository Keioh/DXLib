#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "data/res_data/enemy/enemy_data.h"
#include "data/res_data/enemy/move_pattern.h"
#include "data/res_data/enemy/enemy_attack.h"
#include "diploidPhysics/diploidPhysics.h"
#include "data/res_data/anime/animation.h"
#include "data/res_data/anime/animation.h"

class _TestEnemy
{
private:
	DiploidImageV2 counter_icon_image;

	DiploidCircleV2 circle;

	//アニメ	
	int anime_frame_volume = 4;//アニメーションに使う画像の枚数
	int anime_time = 0;//コマ送りの待機時間
	int play_time = 4;//アニメーション再生速度
	int anime_count = 0;//現在のコマ	
	DiploidImageV2 move_image[5];//アニメ用画像の読み込み


	std::list<EnemyAttack> attack_list;
	EnemyAttack attack;

	EnemyData data;
	EnemyData data_buffer;

	MovePattern move_pattern;
	MoveData move_data;

	float counter_time_buffer;
	bool counter_flag = false;

	bool destory_flag = false;


public:
	void SetEnemyData(EnemyData new_data);
	void LoadGraphics();
	void LoadHandles(int handle);
	void Init();
	void PushBackMoveDate(MoveData date);//Init()の後に呼び出すこと
	void Updata();
	void Draw(bool draw = true);

	void isSetDestoryFlag(bool new_flag);
	void SetMoveSpeed(float new_speed);
	bool GetCounterFlag();

	EnemyData* GetDataPtr();
	DiploidCircleV2* GetCirclePtr();
	std::list<EnemyAttack>* GetAttackListPtr();

};