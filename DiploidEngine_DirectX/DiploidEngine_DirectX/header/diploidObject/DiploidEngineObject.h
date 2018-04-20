#pragma once
#include "DxLib.h"

class DiploidEngineObject
{
private:

public:
	bool mouse_point_move_flag = false;
	VECTOR position;//ˆÊ’u
	VECTOR size;//‘å‚«‚³(z‚Í‰~‚Ì”¼Œa)	
	int mouse_position_x, mouse_position_y;
	unsigned int color;//F
	int fill;//“h‚è‚Â‚Ô‚µ
	int thickness;//‘¾‚³

	VECTOR move_speed;
	float move_size;

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};
};