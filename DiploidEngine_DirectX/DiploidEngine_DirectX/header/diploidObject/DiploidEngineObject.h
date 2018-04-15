#pragma once
#include "DxLib.h"

class DiploidEngineObject
{
private:

public:
	VECTOR position;//ˆÊ’u
	VECTOR size;//‘å‚«‚³(z‚Í‰~‚Ì”¼Œa)
	unsigned int color;//F
	int fill;//“h‚è‚Â‚Ô‚µ
	int thickness;//‘¾‚³

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};
};