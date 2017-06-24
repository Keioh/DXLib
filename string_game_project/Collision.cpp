#include "Collision.h"

Collision::Collision()
{

}

bool Collision::BoxCollider(int position_x, int size_x, int position_y, int size_y, bool wire)
{
	GetMousePoint(&x, &y);//���݂̃J�[�\���ʒu���K��

	if (wire == true) DrawBox(position_x, position_y, position_x + size_x, position_y + size_y, GetColor(red, green, blue), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���B)

	if (position_x < x && position_x + size_x > x)
	{
		if ( position_y < y && position_y + size_y > y)
		{
			red = 255;
			blue = 0;
			return true;
		}
		else
		{
			red = 0;
			blue = 255;
			return false;
		}
	}
	else
	{
		red = 0;
		blue = 255;
		return false;
	}	
}

bool Collision::CircleCollider(int position_x, int position_y, int size_r, bool wire)
{
	GetMousePoint(&x, &y);//���݂̃J�[�\���ʒu���K��

	if (wire == true) DrawCircle(position_x, position_y, size_r, GetColor(red, green, blue), FALSE);//���C���[��\��(�q�b�g������Ԃŕ\���B)

	if (((x - position_x) * (x - position_x)) + ((y - position_y) * (y - position_y)) <= (size_r * size_r))
	{
		red = 255;
		blue = 0;
		return true;
	}
	else
	{
		red = 0;
		blue = 255;
		return false;
	}
}