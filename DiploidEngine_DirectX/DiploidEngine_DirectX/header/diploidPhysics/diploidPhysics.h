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

	bool jump_button = false;//jump_button����������true

	float Gravity(float fall_speed = 1.0f, float fall_max = 10.0f, float jump_max = 100.0f);//�I�u�W�F�N�g�ɏd�͂�t�^�������Ƃ��Ɏg�p���܂��B(fall_speed�ɂ͏����x�Afall_max�ɂ͗�����ő呬�x���w��)
	void GravityReset();//�d�͂�0�Ƀ��Z�b�g���܂��B

	void JumpOn();
	void JumpOff();

};