#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidEngineImage
{
private:

public:
	int handl;
	VECTOR position;

	void Load(const char* path);
	void Draw(bool draw = true);
};