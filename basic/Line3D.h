#pragma once
#include "stdio.h"
#include "DxLib.h"
#include "ObjectVector.h"

class Line3D
{
private:

public:
	Line3D() {};

	float x1, x2;
	float z1, z2;

	void Draw(VECTOR pos1, VECTOR pos2, unsigned int color);
};