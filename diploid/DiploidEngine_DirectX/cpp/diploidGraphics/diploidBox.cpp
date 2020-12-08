#include "diploidGraphics\diploidBox.h"

DiploidBox::DiploidBox()
{
	DiploidBox::mouse_point_move_flag = false;
	DiploidBox::center_position_draw_flag = false;//?}?E?X??]????????
}

DiploidBox::~DiploidBox()
{

}


void DiploidBox::Init(VECTOR position, VECTOR size)
{
	DiploidBox::position = origin_position = position;
	DiploidBox::size = origin_size = size;

	center_position = VAdd(VScale(DiploidBox::size, 0.5f), DiploidBox::position);
}

void DiploidBox::Update()
{
	if (mouse_point_move_flag == false)
	{
		anime_position = VAdd(anime_position, move_speed);
		position = VAdd(anime_position, origin_position);
		center_position = VAdd(center_position, move_speed);

		anime_size = VAdd(anime_size, move_size);
		size = VAdd(anime_size, origin_size);

		move_speed = VGet(0,0,0);
	}
	else
	{
		GetMousePoint(&mouse_position_x, &mouse_position_y);

		position.x = mouse_position_x - (size.x / 2);//?}?`????S????`?œ®????????T?C?Y??1/2??????B
		position.y = mouse_position_y - (size.y / 2);//?}?`????S????`?œ®????????T?C?Y??1/2??????B

		anime_size = VAdd(anime_size, move_size);
		size = VAdd(anime_size, origin_size);
	}
}

void DiploidBox::Draw(bool wire)
{
	if (wire == true)
	{
		DrawBox(position.x, position.y, position.x + size.x, position.y + size.y, color, fill);

		if (DiploidBox::center_position_draw_flag == true)
		{
			DrawCircle(center_position.x, center_position.y, 2, color);
		}

		//DrawNameTag();
	}
}


VECTOR DiploidBox::SetCenterPosition(VECTOR new_center_position)
{
	center_position = new_center_position;

	return new_center_position;
}

VECTOR DiploidBox::GetSize()
{
	return DiploidBox::size;
}

VECTOR DiploidBox::GetPosition(VECTOR get_pos)
{
	VECTOR buffer;

	//????
	if ((get_pos.x == 0) && (get_pos.y == 0))
	{
		buffer = DiploidBox::position;

		return buffer;
	}

	//?E??
	if ((get_pos.x == 1) && (get_pos.y == 0))
	{
		buffer.x = DiploidBox::position.x + DiploidBox::size.x;
		buffer.y = DiploidBox::position.y;
		buffer.z = DiploidBox::position.z;


		return buffer;
	}

	//????
	if ((get_pos.x == 0) && (get_pos.y == 1))
	{
		buffer.x = DiploidBox::position.x;
		buffer.y = DiploidBox::position.y + DiploidBox::size.y;
		buffer.z = DiploidBox::position.z;


		return buffer;
	}

	//?E??
	if ((get_pos.x == 1) && (get_pos.y == 1))
	{
		buffer.x = DiploidBox::position.x + DiploidBox::size.x;
		buffer.y = DiploidBox::position.y + DiploidBox::size.y;
		buffer.z = DiploidBox::position.z;


		return buffer;
	}
}

VECTOR DiploidBox::GetCenterPosition()
{
	return center_position;
}


void DiploidBox::TransformScale(float scale)
{
	VScale(DiploidBox::size, scale);
}


void DiploidBox::DrawNameTag()
{
	if (SetDrawNameTagFlag() == TRUE)
	{
		#pragma acc kernels
		for (int count = 0; count != 1; ++count)
		{
			DrawString(GetPosition().x + (count * 20), GetPosition().y, &name_tag[count], GetColor(255, 255, 255));
		}
	}
}

int DiploidBox::SetDrawNameTagFlag(int flag)
{
	return name_tag_flag = flag;
}

std::string DiploidBox::GetNameTag()
{
	return name_tag;
}