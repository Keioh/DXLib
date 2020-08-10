#include "data/res_data/enemy/enemy_attack.h"


void EnemyAttack::Init(VECTOR pos, EnemyData data)
{
	circle.Init(pos, data.attack_size, GetColor(150, 150, 150));
}

void EnemyAttack::Updata()
{

}

void EnemyAttack::Draw(bool draw)
{
	circle.Draw(draw);
}


DiploidCircleV2* EnemyAttack::GetCirclePtr()
{
	return& circle;
}