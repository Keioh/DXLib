#include "diplomacy.h"

void Diplomacy::Init()
{
	diplomacy_button.Init();
}

void Diplomacy::Load()
{
	diplomacy_button.Load("pack/GameObject/GameUI/diplomacy/diplomacy_button.png");
}

void Diplomacy::Draw(int pos_x, int pos_y, bool wire)
{
	diplomacy_button.BoxUI_Button(pos_x, pos_y, 1, wire);
}