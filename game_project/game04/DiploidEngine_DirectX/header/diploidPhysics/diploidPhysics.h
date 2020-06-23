#pragma once
#include <math.h>
#include "DxLib.h"

class DiploidPhysics
{
private:

	float gravity = 0.98f;//重力加速度
	float jump = 0.0f;
	float jump_power = 12.0f;
	float jump_time = 0.0f;


	float y;
	float gravity_buffer = 0.0f;//保存用
	float jump_buffer = 0.0f;//保存用
	float fall_max_buffer = 0.0f;

	bool flag = false;

public:
	DiploidPhysics() {};
	~DiploidPhysics() {};

	float Jump();

};