#pragma once
#include "building.h"
#include "struct_set.h"

class MeshRegion
{
private:

public:
	Building building;
	MODE mode;

	void Init();
	void Load();
	void Draw(VECTOR pos, bool wire = false);
	void DrawUI(int pos_x, int pos_y, bool wire = false);
};