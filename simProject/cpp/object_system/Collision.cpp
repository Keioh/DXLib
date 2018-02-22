#include "Collision.h"


bool Collision::BoxColliderMouse(int position_x, int size_x, int position_y, int size_y, bool wire)
{
	if (active == true)
	{
		GetMousePoint(&x, &y);//現在のカーソル位置を取得

		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox(position_x + double_line, position_y + double_line, position_x + (size_x - double_line), position_y + (size_y - double_line), GetColor(red, green, blue), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}

		if (position_x < x && position_x + size_x > x)
		{
			if (position_y < y && position_y + size_y > y)
			{

				red = 255;
				blue = 0;
				green = 0;

				return hit = true;
			}
			else
			{
				red = 0;
				blue = 255;
				green = 0;

				return hit = false;
			}
		}
		else
		{
			red = 0;
			blue = 255;
			green = 0;

			return hit = false;
		}
	}
	else
	{
		return hit = false;
	}
}

bool Collision::CircleColliderMouse(int position_x, int position_y, int size_r, bool wire)
{
	if (active == true)
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
			return hit = true;
		}
		else
		{
			red = 0;
			blue = 255;
			green = 0;
			return hit = false;
		}
	}
	else
	{
		return hit = false;
	}
}

bool Collision::TriangleColliderMouse3D(VERTEX3D triangle_vertex_1, VERTEX3D triangle_vertex_2, VERTEX3D triangle_vertex_3, bool wire)
{
	if (active == true)
	{
		GetMousePoint(&x, &y);//現在のカーソル位置を習得

		mouse_pos_world_near = ConvScreenPosToWorldPos(VGet(x, y, 0.0f));//手前
		mouse_pos_world_far = ConvScreenPosToWorldPos(VGet(x, y, 1.0f));//奥

		hit3D = HitCheck_Line_Triangle(mouse_pos_world_near, mouse_pos_world_far, triangle_vertex_1.pos, triangle_vertex_2.pos, triangle_vertex_3.pos);

		if (wire == true)
		{
			if (hit3D.HitFlag == 1)
			{
				DrawTriangle3D(triangle_vertex_1.pos, triangle_vertex_2.pos, triangle_vertex_3.pos, GetColor(255, 0, 0), FALSE);
			}
			else
			{
				DrawTriangle3D(triangle_vertex_1.pos, triangle_vertex_2.pos, triangle_vertex_3.pos, GetColor(0, 0, 255), FALSE);
			}
		}

		return hit = hit3D.HitFlag;
	}
	else
	{
		return hit = hit3D.HitFlag;
	}
}
