#include "diploidGraphics\diploidPoint.h"

void DiploidPoint::Init(VECTOR position)
{
	center_position = position;
}

void DiploidPoint::Update()
{
	//�A�j���[�V�����L����
	if (mouse_point_move_flag == false)
	{
		anime_position = VAdd(anime_position, move_speed);//�A�j���[�V�����ňړ���������ۑ�
		position = VAdd(center_position, anime_position);//�I�u�W�F�N�g��`�ʂ����ʒu�ƈړ���������ۑ�

		move_speed = VGet(0, 0, 0);
	}
	else
	{
		GetMousePoint(&mouse_position_x, &mouse_position_y);
		position.x = mouse_position_x;
		position.y = mouse_position_y;
	}
}

void DiploidPoint::Draw(bool wire)
{
	DrawPixel(position.x, position.y, color);
}

std::string DiploidPoint::GetNameTag()
{
	return name_tag;
}