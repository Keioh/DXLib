#include "infomation_bar.h"

void InfomationBar::Init()
{

}

void InfomationBar::Load()
{
	back_wall_graphics = LoadGraph("pack/GameObject/GameUI/infomation_bar/back_wall.png");
}

void InfomationBar::Draw(int pos_x, int pos_y, bool wire)
{
	DrawGraph(pos_x, pos_y, back_wall_graphics, TRUE);
}