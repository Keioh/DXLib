#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "data/res_data/enemy/enemy_data.h"
#include "data/res_data/enemy/move_pattern.h"
#include "data/res_data/enemy/enemy_attack.h"
#include "diploidPhysics/diploidPhysics.h"
#include "data/res_data/anime/animation.h"

class _TestEnemy
{
private:
	DiploidImageV2 counter_icon_image;

	DiploidCircleV2 circle;

	std::list<EnemyAttack> attack_list;
	EnemyAttack attack;

	EnemyData data;
	EnemyData data_buffer;

	MovePattern move_pattern;
	MoveData move_data;

	float counter_time_buffer;
	bool counter_flag = false;

public:
	void SetEnemyData(EnemyData new_data);
	void LoadGraphics();
	void Init();
	void Updata();
	void Draw(bool draw = true);

	void SetMoveSpeed(float new_speed);
	bool GetCounterFlag();

	EnemyData* GetDataPtr();
	DiploidCircleV2* GetCirclePtr();
	std::list<EnemyAttack>* GetAttackListPtr();

};