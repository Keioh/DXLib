#pragma once
#include <vector>
#include "DxLib.h"
#include  "ver2.0/Graphics/DiploidBoxV2.h"
#include  "ver2.0/Graphics/DiploidImageV2.h"
#include "system\DiploidEngineSetting.h"

class DiploidScreenGraphics
{
private:
	DiploidEngineSetting setting;

	int make_graphics_handl, graphics_handle, final_graphics;
	int x, y;


public:

	//void Creat(float scale);

	void Draw(float scale);
};