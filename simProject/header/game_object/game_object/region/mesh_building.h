#pragma once
#include "building.h"
#include "struct_set.h"

class MeshBuilding
{
private:

public:
	Building building0, building1, building2;//0=更地オブジェクト、1=交易所オブジェクト、2=研究所オブジェクト

	int affiliation_faction = 0;//所属しているファクション(0で無所属)
	int building_type = 0;//建物の種類(0=更地、1=交易所、2=研究所)

	void Init();
	void Load();
	void Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos);
	void Updata();
	void Draw(MODE mode, bool wire = false);
	void DrawUI(int pos_x, int pos_y, MODE mode, bool wire = false);
};