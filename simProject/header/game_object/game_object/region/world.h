//各地域をまとめる処理
//このworldをGameSceneで呼び出す。

#pragma once
#include "mesh_building.h"

class World
{
private:
	int select = 0;

public:
	MeshBuilding test1;
	MeshBuilding test2;
	MeshBuilding test3;
	MeshBuilding test4;

	void Init();
	void Load();
	void Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos);
	void Draw(MODE mode, bool wire = false);
	void DrawUI(int window_x, int window_y, MODE mode, Filer config, bool wire = false);
};