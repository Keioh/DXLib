#pragma once
#include "building.h"
#include "struct_set.h"

class MeshBuilding
{
private:

public:
	Building building;

	int affiliation_faction;//所属しているファクション(0で無所属)
	int building_type;//建物の種類

	void Init();
	void Load();
	void Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos);
	void Draw(MODE mode, bool wire = false);
	void DrawUI(int pos_x, int pos_y, bool wire = false);
};