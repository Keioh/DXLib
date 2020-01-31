#include "ver2.0/Graphics/DiploidCircleV2.h"

void DiploidCircleV2::Init(VECTOR pos, float radi, unsigned int color, bool fill, float thickness)
{
	position = pos;
	radius = radi;
	object_color = color;
	object_fill = fill;
	object_thickness = thickness;
}

void DiploidCircleV2::Updata()
{

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