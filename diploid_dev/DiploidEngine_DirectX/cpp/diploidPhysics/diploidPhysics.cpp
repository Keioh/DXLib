#include "diploidPhysics/diploidPhysics.h"

void DiploidPhysics::SetGravitySize(float size)
{
	gravity = size;
}

float DiploidPhysics::Gravity(float fall_max)
{
	if (gravity_buffer > fall_max)
	{
		gravity_buffer = fall_max;
	}

	gravity_buffer = gravity + gravity_buffer;

	return -gravity_buffer;
}

float DiploidPhysics::GetGracitySize()
{
	return gravity;
}

void DiploidPhysics::GravityReset()
{
	gravity_buffer = 0.0f;
}


float DiploidPhysics::Jump(float jump_power)
{
	if (jump_flag == true)
	{
		if (jump_buffer > jump_power)
		{
			jump_buffer = jump_power;
			GravityReset();
			jump_flag = false;
		}

		jump_buffer = gravity + jump_buffer;
	}
	else
	{
		JumpReset();
	}

	return jump_buffer;
}

void DiploidPhysics::JumpOn()
{
	jump_flag = true;
}

void DiploidPhysics::JumpReset()
{
	jump_buffer = 0.0f;
}