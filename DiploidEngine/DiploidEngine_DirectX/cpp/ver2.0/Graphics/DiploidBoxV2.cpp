#include "ver2.0/Graphics/DiploidBoxV2.h"


void DiploidBoxV2::Init(VECTOR pos, VECTOR size, unsigned int color, float scale, bool fill, float thickness)
{
	position = pos;	
	object_scale_x = scale;
	object_scale_y = scale;
	box_size = VGet(size.x * object_scale_x, size.y * object_scale_y, 0.0f);
	object_color = color;
	object_fill = fill;
	object_thickness = thickness;
}

void DiploidBoxV2::MoveUpdate()
{
	this->position.x += this->move_speed.x;
	this->position.y += this->move_speed.y;
	this->position.z += this->move_speed.z;

	move_speed = VGet(0, 0, 0);
}

void DiploidBoxV2::Draw(bool draw)
{
	if (draw == true)
	{
		DrawBoxAA(position.x, position.y, position.x + box_size.x, position.y + box_size.y, object_color, object_fill, object_thickness);
	}
}


void DiploidBoxV2::SetColor(unsigned int new_color)
{
	this->object_color = new_color;
}

void DiploidBoxV2::SetPosition(VECTOR new_pos)
{
	this->position = new_pos;
}

void DiploidBoxV2::SetSize(VECTOR new_size)
{
	this->box_size = VGet(new_size.x * object_scale_x, new_size.y * object_scale_y, 0.0f);
}

void DiploidBoxV2::SetScale(float new_scale_x, float new_scale_y)
{
	this->object_scale_x = new_scale_x;
	this->object_scale_y = new_scale_y;
}

void DiploidBoxV2::SetFill(bool new_fill)
{
	this->object_fill = new_fill;
}

void DiploidBoxV2::SetThickness(float new_thickness)
{
	this->object_thickness = new_thickness;
}


void DiploidBoxV2::SetName(string new_name)
{
	this->name = new_name;
}

void DiploidBoxV2::SetObjectNumber(int new_number)
{
	this->object_number = new_number;
}

void DiploidBoxV2::SetHitFlag(bool new_hit_flag)
{
	this->hit_flag = new_hit_flag;
}

void DiploidBoxV2::SetMoveSpeed(VECTOR new_move_speed)
{
	this->move_speed = new_move_speed;

}

void DiploidBoxV2::SetMoveSpeed(float angle, float new_move_speed)
{
	this->move_speed.x = cosf(angle) * new_move_speed;
	this->move_speed.y = sinf(angle) * new_move_speed;

	this->move_angle = angle;
}

void DiploidBoxV2::SetLife(float new_life)
{
	this->object_life = new_life;
}

void DiploidBoxV2::SetDestoryFlag(bool new_flag)
{
	this->destory_flag = new_flag;
}

void DiploidBoxV2::SetMainCameraFlag(bool new_flag)
{
	this->main_camera = new_flag;
}


void DiploidBoxV2::AddLife(float add_val)
{
	this->object_life += add_val;
}

void DiploidBoxV2::SubLife(float sub_val)
{
	this->object_life -= sub_val;
}


VECTOR DiploidBoxV2::GetPosition()
{
	return this->position;
}

VECTOR DiploidBoxV2::GetSize()
{
	return this->box_size;
}

float DiploidBoxV2::GetScaleX()
{
	return this->object_scale_x;
}

float DiploidBoxV2::GetScaleY()
{
	return this->object_scale_y;
}

float DiploidBoxV2::GetThickness()
{
	return this->object_thickness;
}

unsigned int DiploidBoxV2::GetColor()
{
	return this->object_color;
}

bool DiploidBoxV2::GetFill()
{
	return this->object_fill;
}

string DiploidBoxV2::GetName()
{
	return this->name;
}

int DiploidBoxV2::GetObjectNumber()
{
	return this->object_number;
}

bool DiploidBoxV2::GetHitFlag()
{
	return this->hit_flag;
}

VECTOR DiploidBoxV2::GetMoveSpeed()
{
	return this->move_speed;
}

float DiploidBoxV2::GetMoveAngle()
{
	return this->move_angle;
}

float DiploidBoxV2::GetLife()
{
	return this->object_life;
}

bool DiploidBoxV2::GetDestoryFlag()
{
	return this->destory_flag;
}

bool DiploidBoxV2::GetMainCameraFlag()
{
	return this->main_camera;
}