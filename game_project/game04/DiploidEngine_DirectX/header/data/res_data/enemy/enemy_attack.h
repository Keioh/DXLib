#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "data/res_data/enemy/enemy_data.h"

class EnemyAttack
{
private:
	DiploidCircleV2 circle;

public:
	void Init(VECTOR pos, EnemyData data);
	void Updata();
	void Draw(bool draw = true);

	DiploidCircleV2* GetCirclePtr();

};