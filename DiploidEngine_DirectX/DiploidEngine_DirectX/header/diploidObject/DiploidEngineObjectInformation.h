#pragma once
#include "DxLib.h"

class DiploidEngineObjectInformation
{
private:

public:
	int name_tag;//enum NAME‚Å“o˜^‚µ‚½‚à‚Ì‚ğ‘ã“ü

	bool mouse_point_move_flag = false;
	VECTOR position;//ˆÊ’u
	VECTOR size;//‘å‚«‚³(z‚Í‰~‚Ì”¼Œa)	
	int mouse_position_x, mouse_position_y;
	unsigned int color;//F
	int fill;//“h‚è‚Â‚Ô‚µ
	int thickness;//‘¾‚³

	//ÀÛ‚É“®‚©‚·‚Æ‚«‚É•ÏX‚·‚é•Ï”
	VECTOR move_speed;
	VECTOR move_size;

	//Impact‚µ‚½‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO
	bool impacted = false;
	bool destory = false;

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};

	virtual void Destory() { impacted = destory = true; };
};