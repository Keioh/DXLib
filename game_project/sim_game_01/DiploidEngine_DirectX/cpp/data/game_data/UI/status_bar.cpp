#include "data/game_data/UI/status_bar.h"

void StatusBar::Load()
{
	status_bar.image.Load("texter/game/status_bar/status_bar.png");

}

void StatusBar::Init(VECTOR position)
{
	status_bar.image.Init(VGet(position.x + (640 / 2), position.y + (128 / 2), 0));
}

void StatusBar::Push(DiploidEngineImpact& impact)
{

}

void StatusBar::Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	status_bar.image.Updata();
}

void StatusBar::Draw(bool draw)
{
	status_bar.image.Draw();
}