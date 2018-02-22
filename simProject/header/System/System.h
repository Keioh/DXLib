#pragma once
#include "ObjectVector.h"

class System
{

public:
	System();
	~System(){};

	window size;
	int fullscreen;

	void Dx_Init(bool w_mode, int r, int g, int b, char* name);
	void Dx_End();
};