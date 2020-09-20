#include "ver2.0/Graphics/DiploidCircleV2.h"

void DiploidCircleV2::Init(VECTOR pos, float radi, unsigned int color, bool fill, float thickness)
{
	position = pos;
	radius = radi;
	object_color = color;
	object_fill = fill;
	object_thickness = thickness;
}

void DiploidCircleV2::MoveUpdate()
{
	this->position.x += this->move_speed.x;
	this->position.y += this->move_speed.y;
	this->position.z += this->move_speed.z;

	move_speed = VGet(0, 0, 0);
}

void DiploidCircleV2::Draw(bool draw)
{
	if (draw == true)
	{
		DrawCircleAA(position.x, position.y, radius, 128, object_color, object_fill, object_thickness);
	}
}


void DiploidCircleV2::SetColor(unsigned int new_color)
{
	this->object_color = new_color;
}

void DiploidCircleV2::SetPosition(VECTOR new_pos)
{
	this->position = new_pos;
}

void DiploidCircleV2::SetRadius(float new_radius)
{
	this->radius = new_radius;
}

void DiploidCircleV2::SetFill(bool new_fill)
{
	this->object_fill = new_fill;
}

void DiploidCircleV2::SetThickness(float new_thickness)
{
	this->object_thickness = new_thickness;
}


void DiploidCircleV2::SetName(string new_name)
{
	this->name = new_name;
}

void DiploidCircleV2::SetObjectNumber(int new_number)
{
	this->object_number = new_number;
}

void DiploidCircleV2::SetHitFlag(bool new_hit_flag)
{
	this->hit_flag = new_hit_flag;
}

void DiploidCircleV2::SetMoveSpeed(VECTOR new_move_speed)
{
	this->move_speed = new_move_speed;
}

void DiploidCircleV2::SetMoveSpeed(float angle, float new_move_speed)
{
	this->move_speed.x = cosf(angle) * new_move_speed;
	this->move_speed.y = sinf(angle) * new_move_speed;

	this->move_angle = angle;
}

void DiploidCircleV2::SetLife(float new_life)
{
	this->object_life = new_life;
}

void DiploidCircleV2::SetDestoryFlag(bool new_flag)
{
	this->destory_flag = new_flag;
}

void DiploidCircleV2::SetMainCameraFlag(bool new_flag)
{
	this->main_camera = new_flag;
}


void DiploidCircleV2::AddLife(float add_val)
{
	this->object_life += add_val;
}

void DiploidCircleV2::SubLife(float sub_val)
{
	this->object_life -= sub_val;
}


VECTOR DiploidCircleV2::GetPosition()
{
	return this->position;
}

float DiploidCircleV2::GetRadius()
{
	return this->radius;
}

unsigned int DiploidCircleV2::GetColor()
{
	return this->object_color;
}

bool DiploidCircleV2::GetFill()
{
	return this->object_fill;
}

float DiploidCircleV2::GetThickness()
{
	return this->object_thickness;
}

string DiploidCircleV2::GetName()
{
	return this->name;
}

int DiploidCircleV2::GetObjectNumber()
{
	return this->object_number;
}

bool DiploidCircleV2::GetHitFlag()
{
	return this->hit_flag;
}

VECTOR DiploidCircleV2::GetMoveSpeed()
{
	return this->move_speed;
}

float DiploidCircleV2::GetMoveAngle()
{
	return this->move_angle;
}

float DiploidCircleV2::GetLife()
{
	return this->object_life;
}

bool DiploidCircleV2::GetDestoryFlag()
{
	return this->destory_flag;
}

bool DiploidCircleV2::GetMainCameraFlag()
{
	return this->main_camera;
}


size_t DiploidCircleV2::GetHitPointsVolume()
{
	if (!hit_points_list.empty())
	{
		return this->hit_points_list.size();
	}
	else
	{
		return 0;
	}
}

VECTOR DiploidCircleV2::GetHitPosition()
{
	if (!hit_points_list.empty())
	{
		VECTOR buffer = { 0,0,0 };

		buffer.x = hit_points_list_iterator->x;
		buffer.y = hit_points_list_iterator->y;
		buffer.z = hit_points_list_iterator->z;

		return buffer;
	}
	else
	{
		return { -1,-1,-1 };
	}
}

list<VECTOR>::iterator DiploidCircleV2::GetHitPointsListIterator(list<VECTOR>::iterator* pointer_to_iterator)
{
	hit_points_list_iterator = hit_points_list.begin();

	pointer_to_iterator = &hit_points_list_iterator;

	return this->hit_points_list_iterator;
}

list<VECTOR>::iterator DiploidCircleV2::GetHitPointsListIterator()
{
	return this->hit_points_list_iterator = this->hit_points_list.begin();
}

list<VECTOR>* DiploidCircleV2::GetHitPointsListPointer()
{
	hit_points_list_pointer = &hit_points_list;

	return hit_points_list_pointer;
}