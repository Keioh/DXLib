#include "research.h"

void Research::Init()
{
	research_button.Init();
}

void Research::Load()
{
	research_button.Load("pack/GameObject/GameUI/research/research_button.png");
}

void Research::Draw(int pos_x, int pos_y, bool wire)
{
	research_button.BoxUI_Button(pos_x, pos_y, 1, wire);
}