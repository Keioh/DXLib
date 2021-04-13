#include "ver2.0/Graphics/DiploidBoxV3.h"


void DiploidBoxV3::Init(VECTOR pos, VECTOR size, unsigned int color, float scale, bool fill, float thickness)
{
	position = pos;	
	object_scale_x = scale;
	object_scale_y = scale;
	box_size = VGet(size.x * object_scale_x, size.y * object_scale_y, 0.0f);
	object_color = color;
	object_fill = fill;
	object_thickness = thickness;
}

void DiploidBoxV3::MoveUpdate()
{
	this->position.x += this->move_speed.x;
	this->position.y += this->move_speed.y;
	this->position.z += this->move_speed.z;

	move_speed = VGet(0, 0, 0);
}

void DiploidBoxV3::Draw(bool draw)
{
	if (draw == true)
	{
		//DrawBoxAA(position.x, position.y, position.x + box_size.x, position.y + box_size.y, object_color, object_fill, object_thickness);

		DrawLineAA(position.x, position.y, position.x + box_size.x, position.y, object_color);//ã
		DrawLineAA(position.x, position.y + box_size.y, position.x + box_size.x, position.y + box_size.y, object_color);//‰º
		DrawLineAA(position.x, position.y, position.x, position.y + box_size.y, object_color);//¶
		DrawLineAA(position.x + box_size.x, position.y, position.x + box_size.x, position.y + box_size.y + 1, object_color);//‰E

		if (object_fill == true)
		{
			DrawTriangle(position.x, position.y, position.x + box_size.x, position.y, position.x, position.y + box_size.y, object_color, TRUE);
			DrawTriangle(position.x, position.y + box_size.y, position.x + box_size.x, position.y, position.x + box_size.x, position.y + box_size.y + 1, object_color, TRUE);
		}
	}
}


void DiploidBoxV3::SetColor(unsigned int new_color)
{
	this->object_color = new_color;
}

void DiploidBoxV3::SetPosition(VECTOR new_pos)
{
	this->position = new_pos;
}

void DiploidBoxV3::SetSize(VECTOR new_size)
{
	this->box_size = VGet(new_size.x * object_scale_x, new_size.y * object_scale_y, 0.0f);
}

void DiploidBoxV3::SetScale(float new_scale_x, float new_scale_y)
{
	this->object_scale_x = new_scale_x;
	this->object_scale_y = new_scale_y;
}

void DiploidBoxV3::SetFill(bool new_fill)
{
	this->object_fill = new_fill;
}

void DiploidBoxV3::SetThickness(float new_thickness)
{
	this->object_thickness = new_thickness;
}


void DiploidBoxV3::SetName(string new_name)
{
	this->name = new_name;
}

void DiploidBoxV3::SetObjectNumber(int new_number)
{
	this->object_number = new_number;
}

void DiploidBoxV3::SetHitFlag(bool new_hit_flag)
{
	this->hit_flag = new_hit_flag;
}

void DiploidBoxV3::SetMoveSpeed(VECTOR new_move_speed)
{
	this->move_speed = new_move_speed;

}

void DiploidBoxV3::SetMoveSpeed(float angle, float new_move_speed)
{
	this->move_speed.x = cosf(angle) * new_move_speed;
	this->move_speed.y = sinf(angle) * new_move_speed;

	this->move_angle = angle;
}

void DiploidBoxV3::SetLife(float new_life)
{
	this->object_life = new_life;
}

void DiploidBoxV3::SetDestoryFlag(bool new_flag)
{
	this->destory_flag = new_flag;
}

void DiploidBoxV3::SetMainCameraFlag(bool new_flag)
{
	this->main_camera = new_flag;
}


void DiploidBoxV3::AddLife(float add_val)
{
	this->object_life += add_val;
}

void DiploidBoxV3::SubLife(float sub_val)
{
	this->object_life -= sub_val;
}


VECTOR DiploidBoxV3::GetPosition()
{
	return this->position;
}

VECTOR DiploidBoxV3::GetSize()
{
	return this->box_size;
}

float DiploidBoxV3::GetScaleX()
{
	return this->object_scale_x;
}

float DiploidBoxV3::GetScaleY()
{
	return this->object_scale_y;
}

float DiploidBoxV3::GetThickness()
{
	return this->object_thickness;
}

unsigned int DiploidBoxV3::GetColor()
{
	return this->object_color;
}

bool DiploidBoxV3::GetFill()
{
	return this->object_fill;
}

string DiploidBoxV3::GetName()
{
	return this->name;
}

int DiploidBoxV3::GetObjectNumber()
{
	return this->object_number;
}

bool DiploidBoxV3::GetHitFlag()
{
	return this->hit_flag;
}

VECTOR DiploidBoxV3::GetMoveSpeed()
{
	return this->move_speed;
}

float DiploidBoxV3::GetMoveAngle()
{
	return this->move_angle;
}

float DiploidBoxV3::GetLife()
{
	return this->object_life;
}

bool DiploidBoxV3::GetDestoryFlag()
{
	return this->destory_flag;
}

bool DiploidBoxV3::GetMainCameraFlag()
{
	return this->main_camera;
}