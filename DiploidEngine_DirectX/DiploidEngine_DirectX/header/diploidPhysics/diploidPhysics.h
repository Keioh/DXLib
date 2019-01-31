#pragma once
#include "DxLib.h"

class DiploidPhysics
{
private:

	float gravity = 0.98f;//重力加速度
	float jump = 0.0f;

	float gravity_buffer = 0.0f;//保存用
	float jump_buffer = 0.0f;//保存用

public:
	DiploidPhysics() {};
	~DiploidPhysics() {};

	bool jump_button = false;//jump_buttonを押したらtrue


	void SetGravitySize(float size);//重力加速度を設定します。
	float GetGracitySize();//重力加速度を取得します
	float Gravity(float fall_max = 10.0f);//オブジェクトに重力を付与したいときに使用します。(fall_maxは落ちる最大速度を指定)
	void GravityReset();//重力を0にリセットします。

	float Jump(float jump_max = 100.0f);
	void JumpReset();

};