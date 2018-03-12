#include "mesh_building.h"

void MeshBuilding::Init()
{
	building.Init();
}

void MeshBuilding::Load()
{
	building.Load();
}

void MeshBuilding::Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos)
{
	building.Transform(scale, rote_x, rote_y, rote_z, pos);
}

void MeshBuilding::Updata()
{

}

void MeshBuilding::Draw(MODE mode, bool wire)
{	
	building.Mode(mode);

	building.Draw(wire);
}

void MeshBuilding::DrawUI(int pos_x, int pos_y, MODE mode, bool wire)
{
	building.DrawUI(pos_x, pos_y, wire);

	//接続モードがオンの時のUI表示
	if (mode.connection_mode == 1)
	{

	}
}