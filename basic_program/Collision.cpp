#include "Collision.h"

Collision::Collision()
{

}

bool Collision::BoxColliderMouse(int position_x, int size_x, int position_y, int size_y, bool wire)
{
	GetMousePoint(&x, &y);//現在のカーソル位置を習得

	if (wire == true)
	{
		for (int double_line = 0; double_line < 3; double_line++)
		{
			DrawBox(position_x + double_line, position_y + double_line, position_x + (size_x - double_line), position_y + (size_y - double_line), GetColor(red, green, blue), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
		}
	}

	if (position_x < x && position_x + size_x > x)
	{
		if ( position_y < y && position_y + size_y > y)
		{
			red = 255;
			blue = 0;
			green = 0;
			return true;
		}
	}
	else
	{
		red = 0;
		blue = 255;
		green = 0;
		return false;
	}	
}

bool Collision::CircleColliderMouse(int position_x, int position_y, int size_r, bool wire)
{
	GetMousePoint(&x, &y);//現在のカーソル位置を習得

	if (wire == true)
	{
		for (int double_line = 0; double_line < 3; double_line++)
		{
			DrawCircle(position_x, position_y, size_r - double_line, GetColor(red, green, blue), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
		}
	}

	if (((x - position_x) * (x - position_x)) + ((y - position_y) * (y - position_y)) <= (size_r * size_r))
	{
		red = 255;
		blue = 0;
		green = 0;
		return true;
	}
	else
	{
		red = 0;
		blue = 255;
		green = 0;
		return false;
	}
}