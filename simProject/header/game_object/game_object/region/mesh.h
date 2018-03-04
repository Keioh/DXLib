#pragma once
#include "building.h"

class MeshRegion
{
private:

public:
	Building building;

	void Init();
	void Load();
	void Draw(VECTOR pos, bool wire = false);
	void DrawUI(int pos_x, int pos_y, bool wire = false);
};