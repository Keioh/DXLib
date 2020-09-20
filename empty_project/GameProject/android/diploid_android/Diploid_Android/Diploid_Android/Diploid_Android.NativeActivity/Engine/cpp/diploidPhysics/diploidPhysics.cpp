#include "diploidPhysics/diploidPhysics.h"

float DiploidPhysics::Jump()
{	
	jump_power -= gravity;

	jump = jump_power;

	return -jump;
}