#include "data/res_data/player/player_defense.h"

void PlayerDefense::Init(VECTOR pos)
{
	circle.Init(pos, defense_size, GetColor(0, 0, 255));
}

void PlayerDefense::Updata(DiploidEngineInput* input)
{

}

void PlayerDefense::Draw(bool debug, bool draw)
{
	circle.Draw(draw);
}

void PlayerDefense::SetDefenseSize(float new_size)
{
	defense_size = new_size;
}


DiploidCircleV2* PlayerDefense::GetDefenseCircleObjectPtr()
{
	return &circle;
}