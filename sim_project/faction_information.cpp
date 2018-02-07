#include "faction_information.h"

void FactionInformation::Init()
{
	faction_circle.Init();
}

void FactionInformation::Load()
{
	faction_circle.Load("pack/GameObject/faction/blue_faction.png");
}

void FactionInformation::Draw(int pos_x, int pos_y, bool wire)
{
	faction_circle.CircleUI_Button(pos_x, pos_y, 115, 1, wire);
}