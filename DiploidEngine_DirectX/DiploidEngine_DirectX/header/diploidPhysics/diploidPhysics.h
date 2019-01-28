#pragma once
#include "DxLib.h"

class DiploidPhysics
{
private:

	float gravity = 0.0f;
	float jump = 0.0f;


public:
	DiploidPhysics() {};
	~DiploidPhysics() {};

	bool jump_button = false;//jump_buttonを押したらtrue

	float Gravity(float fall_speed = 1.0f, float fall_max = 10.0f, float jump_max = 100.0f);//オブジェクトに重力を付与したいときに使用します。(fall_speedには初速度、fall_maxには落ちる最大速度を指定)
	void GravityReset();//重力を0にリセットします。

	void JumpOn();
	void JumpOff();

};