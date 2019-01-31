#pragma once
#include "DxLib.h"

class DiploidPhysics
{
private:

	float gravity = 0.98f;//�d�͉����x
	float jump = 0.0f;

	float gravity_buffer = 0.0f;//�ۑ��p
	float jump_buffer = 0.0f;//�ۑ��p

public:
	DiploidPhysics() {};
	~DiploidPhysics() {};

	bool jump_button = false;//jump_button����������true


	void SetGravitySize(float size);//�d�͉����x��ݒ肵�܂��B
	float GetGracitySize();//�d�͉����x���擾���܂�
	float Gravity(float fall_max = 10.0f);//�I�u�W�F�N�g�ɏd�͂�t�^�������Ƃ��Ɏg�p���܂��B(fall_max�͗�����ő呬�x���w��)
	void GravityReset();//�d�͂�0�Ƀ��Z�b�g���܂��B

	float Jump(float jump_max = 100.0f);
	void JumpReset();

};