#include "diploidPhysics/diploidPhysics.h"

float DiploidPhysics::Gravity(float fall_speed, float fall_max, float jump_max)
{
	if (gravity > fall_max)
	{
		gravity = fall_max;
	}

	gravity = fall_speed + gravity;

	return -gravity;
}

void DiploidPhysics::GravityReset()
{
	gravity = 0.0f;
}

void DiploidPhysics::JumpOn()
{
	jump_button = true;//�W�����v�{�^���t���O��true��
}

void DiploidPhysics::JumpOff()
{
	jump_button = false;//�W�����v�{�^���t���O��true��
}