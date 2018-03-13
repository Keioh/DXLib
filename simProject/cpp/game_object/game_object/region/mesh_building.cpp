#include "mesh_building.h"

void MeshBuilding::Init()
{
	building0.Init();
	building1.Init();
	building2.Init();
	building_type = 2;
}

void MeshBuilding::Load()
{
	building0.Load("pack/GameObject/models/empty_lot.png");
	building1.Load("pack/GameObject/models/market_place.png");
	building2.Load("pack/GameObject/models/laboratory.png");
}

void MeshBuilding::Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos)
{
	building0.Transform(scale, rote_x, rote_y, rote_z, pos);
	building1.Transform(scale, rote_x, rote_y, rote_z, pos);
	building2.Transform(scale, rote_x, rote_y, rote_z, pos);
}

void MeshBuilding::Updata()
{

}

void MeshBuilding::Draw(MODE mode, bool wire)
{		
	if (building_type == 0)//建物タイプが更地(0)なら
	{
		building0.Mode(mode);
		building0.Draw(wire);
	}
	else if (building_type == 1)//建物タイプが交易所(1)なら
	{
		building1.Mode(mode);
		building1.Draw(wire);
	}
	else if (building_type == 2)//建物タイプが研究所(2)なら
	{
		building2.Mode(mode);
		building2.Draw(wire);
	}
}

void MeshBuilding::DrawUI(int pos_x, int pos_y, MODE mode, bool wire)
{	
	if (building_type == 0)//建物タイプが更地(0)なら
	{
		building0.DrawUI(pos_x, pos_y, wire);
	}
	else if (building_type == 1)//建物タイプが交易所(1)なら
	{
		building1.DrawUI(pos_x, pos_y, wire);
	}
	else if (building_type == 2)//建物タイプが研究所(2)なら
	{
		building2.DrawUI(pos_x, pos_y, wire);
	}

	//接続モードがオンの時のUI表示
	if (mode.connection_mode == 1)
	{

	}
}