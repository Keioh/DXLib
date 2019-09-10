#include "diploidGraphics\diploidCircle.h"

DiploidCircle::DiploidCircle()
{
	DiploidCircle::center_position_draw_flag = true;
	DiploidCircle::mouse_point_move_flag = false;

}

DiploidCircle::~DiploidCircle()
{

}


void DiploidCircle::Init(VECTOR position, float size)
{
	center_position = position;
	origin_size.z = size;
}

void DiploidCircle::Update()
{
	if (mouse_point_move_flag == false)
	{
		anime_position = VAdd(anime_position, move_speed);//アニメーションで移動した分を保存
		position = VAdd(center_position, anime_position);//オブジェクトを描写した位置と移動した分を保存

		anime_size = VAdd(anime_size, move_size);
		size = VAdd(anime_size, origin_size);
	}
	else
	{
		GetMousePoint(&mouse_position_x, &mouse_position_y);
		size = origin_size;
		position.x = mouse_position_x;
		position.y = mouse_position_y;
	}
}

void DiploidCircle::Draw(bool wire)
{
	if (wire == true)
	{
		DrawCircleAA(position.x, position.y, size.z, 64, color, fill, thickness);

		if (center_position_draw_flag == true)
		{
			DrawCircle(position.x, position.y, 2, color);
		}

		if (SetDrawNameTagFlag() == TRUE)
		{
			//DrawNameTag();
		}
	}
}


float DiploidCircle::GetSize()
{
	return size.z;
}

VECTOR DiploidCircle::GetCenterPosition()
{
	return position;
}

void DiploidCircle::DrawNameTag()
{
	for (int count = 0; count != 1; ++count)
	{
		DrawString(GetCenterPosition().x + (count * 20), GetCenterPosition().y, &name_tag[count], GetColor(255, 255, 255));
	}
}


int DiploidCircle::SetDrawNameTagFlag(int flag)
{
	return name_tag_flag = flag;
}

std::string DiploidCircle::GetNameTag()
{
	return name_tag;
}