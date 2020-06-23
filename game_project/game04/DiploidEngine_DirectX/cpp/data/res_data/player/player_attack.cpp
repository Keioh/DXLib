#include "data/res_data/player/player_attack.h"

void PlayerAttack::Init(VECTOR pos)
{
	circle.Init(pos, attack_size, GetColor(0, 0, 255));
}

void PlayerAttack::Updata(DiploidEngineInput* input)
{

}

void PlayerAttack::Draw(bool debug, bool draw)
{
	circle.Draw(draw);
}


void PlayerAttack::SetAttackSize(float new_size)
{
	attack_size = new_size;
}


DiploidCircleV2* PlayerAttack::GetAttackCircleObjectPtr()
{
	return &circle;
}