//各地域をまとめる処理
//このworldをGameSceneで呼び出す。

#pragma once
#include "mesh_building.h"

class World
{
private:

public:
	MeshBuilding test1;

	void Init();
	void Load();
	void Draw();
};