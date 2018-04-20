#include "diploidGraphics\diploidCircle.h"

void DiploidCircle::Init(VECTOR position, float size)
{
	center_position = position;
	origin_size = size;
}

void DiploidCircle::Update(VECTOR move_speed, float move_size, bool mouse_point)
{
	if (mouse_point == false)
	{
		anime_position = VAdd(anime_position, move_speed);//�A�j���[�V�����ňړ���������ۑ�
		position = VAdd(center_position, anime_position);//�I�u�W�F�N�g��`�ʂ����ʒu�ƈړ���������ۑ�

		anime_size += move_size;
		size.z = anime_size + origin_size;
	}
	else
	{
		GetMousePoint(&mouse_position_x, &mouse_position_y);
		size.z = origin_size;
	}
}

void DiploidCircle::Draw(bool wire)
{
	if (wire == true)
	{
		DrawCircleAA(position.x + mouse_position_x, position.y + mouse_position_y, size.z, 64, color, fill, thickness);
	}
}