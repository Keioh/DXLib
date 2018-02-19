#include "money.h"

void Money::Init()
{
	money = 0;
}

void Money::Draw(int pos_x, int pos_y, bool wire)
{
	DrawFormatString(pos_x, pos_y, GetColor(0, 0, 0), "%d", money);
}