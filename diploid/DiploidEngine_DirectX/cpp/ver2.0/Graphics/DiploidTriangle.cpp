#include "ver2.0/Graphics/DiploidTriangle.h"

void DiploidTriangle::Init(TRIANGLE pos, unsigned int color, float rotation, bool fill, float thickness)
{
	triangle_position = pos;
	radius = rotation;
	object_color = color;
	object_fill = fill;
	object_thickness = thickness;
}

void DiploidTriangle::MoveUpdate()
{
	this->position.x += this->move_speed.x;
	this->position.y += this->move_speed.y;
	this->position.z += this->move_speed.z;

	move_speed = VGet(0, 0, 0);
}

void DiploidTriangle::Draw(bool draw)
{
	if (draw == true)
	{
		DrawTriangleAA(triangle_position.point_one.x, triangle_position.point_one.y, triangle_position.point_two.x, triangle_position.point_two.y, 
			triangle_position.point_three.x, triangle_position.point_three.y, object_color, object_fill);
	}
}


void DiploidTriangle::SetColor(unsigned int new_color)
{
	this->object_color = new_color;
}

void DiploidTriangle::SetPosition(TRIANGLE new_pos)
{
	this->triangle_position = new_pos;
}

void DiploidTriangle::SetRadius(float new_radius)
{
	this->radius = new_radius;
}

void DiploidTriangle::SetFill(bool new_fill)
{
	this->object_fill = new_fill;
}

void DiploidTriangle::SetThickness(float new_thickness)
{
	this->object_thickness = new_thickness;
}


void DiploidTriangle::SetName(string new_name)
{
	this->name = new_name;
}

void DiploidTriangle::SetObjectNumber(int new_number)
{
	this->object_number = new_number;
}

void DiploidTriangle::SetHitFlag(bool new_hit_flag)
{
	this->hit_flag = new_hit_flag;
}

void DiploidTriangle::SetMoveSpeed(VECTOR new_move_speed)
{
	this->move_speed = new_move_speed;
}

void DiploidTriangle::SetMoveSpeed(float angle, float new_move_speed)
{
	this->move_speed.x = cosf(angle) * new_move_speed;
	this->move_speed.y = sinf(angle) * new_move_speed;

	this->move_angle = angle;
}

void DiploidTriangle::SetLife(float new_life)
{
	this->object_life = new_life;
}

void DiploidTriangle::SetDestoryFlag(bool new_flag)
{
	this->destory_flag = new_flag;
}

void DiploidTriangle::SetMainCameraFlag(bool new_flag)
{
	this->main_camera = new_flag;
}


void DiploidTriangle::AddLife(float add_val)
{
	this->object_life += add_val;
}

void DiploidTriangle::SubLife(float sub_val)
{
	this->object_life -= sub_val;
}


TRIANGLE DiploidTriangle::GetPosition()
{
	return this->triangle_position;
}

float DiploidTriangle::GetRadius()
{
	return this->radius;
}

unsigned int DiploidTriangle::GetColor()
{
	return this->object_color;
}

bool DiploidTriangle::GetFill()
{
	return this->object_fill;
}

float DiploidTriangle::GetThickness()
{
	return this->object_thickness;
}

string DiploidTriangle::GetName()
{
	return this->name;
}

int DiploidTriangle::GetObjectNumber()
{
	return this->object_number;
}

bool DiploidTriangle::GetHitFlag()
{
	return this->hit_flag;
}

VECTOR DiploidTriangle::GetMoveSpeed()
{
	return this->move_speed;
}

float DiploidTriangle::GetMoveAngle()
{
	return this->move_angle;
}

float DiploidTriangle::GetLife()
{
	return this->object_life;
}

bool DiploidTriangle::GetDestoryFlag()
{
	return this->destory_flag;
}

bool DiploidTriangle::GetMainCameraFlag()
{
	return this->main_camera;
}

VECTOR DiploidTriangle::GetCenterPosition()
{
	center_pos.x = (triangle_position.point_one.x + triangle_position.point_two.x + triangle_position.point_three.x) / 3;
	center_pos.y = (triangle_position.point_one.y + triangle_position.point_two.y + triangle_position.point_three.y) / 3;

	return center_pos;
}


size_t DiploidTriangle::GetHitPointsVolume()
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

VECTOR DiploidTriangle::GetHitPosition()
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

list<VECTOR>::iterator DiploidTriangle::GetHitPointsListIterator(list<VECTOR>::iterator* pointer_to_iterator)
{
	hit_points_list_iterator = hit_points_list.begin();

	pointer_to_iterator = &hit_points_list_iterator;

	return this->hit_points_list_iterator;
}

list<VECTOR>::iterator DiploidTriangle::GetHitPointsListIterator()
{
	return this->hit_points_list_iterator = this->hit_points_list.begin();
}

list<VECTOR>* DiploidTriangle::GetHitPointsListPointer()
{
	hit_points_list_pointer = &hit_points_list;

	return hit_points_list_pointer;
}