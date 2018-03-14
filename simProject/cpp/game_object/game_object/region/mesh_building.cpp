#include "mesh_building.h"

void MeshBuilding::Init()
{
	window.Init();
	building0.Init();
	building1.Init();
	building2.Init();
	building_type = 2;
}

void MeshBuilding::Load()
{
	window.Load("pack/GameObject/GameUI/building_window/window.png");
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

		if (building0.object_click == true)
		{
			window_flag *= -1;
		}
	}
	else if (building_type == 1)//建物タイプが交易所(1)なら
	{
		building1.Mode(mode);
		building1.Draw(wire);

		if (building1.object_click == true)
		{
			window_flag *= -1;
		}
	}
	else if (building_type == 2)//建物タイプが研究所(2)なら
	{
		building2.Mode(mode);
		building2.Draw(wire);

		if (building2.object_click == true)
		{
			window_flag *= -1;
		}
	}
}

void MeshBuilding::DrawUI(int window_x, int window_y, MODE mode, bool wire)
{	
	if (building_type == 0)//建物タイプが更地(0)なら
	{
		building0.DrawUI(window_x, window_y, wire);
	}
	else if (building_type == 1)//建物タイプが交易所(1)なら
	{
		building1.DrawUI(window_x, window_y, wire);
	}
	else if (building_type == 2)//建物タイプが研究所(2)なら
	{
		building2.DrawUI(window_x, window_y, wire);
	}

	if (window_flag == 1)//フラグがオンならwindowを表示
	{
		window.Draw(window_x - window.graphics_size_x, window_y - window.graphics_size_y, wire);
		if (window.click == true)
		{
			window_flag *= -1;
		}
	}

	//接続モードがオンの時のUI表示
	if (mode.connection_mode == 1)
	{

	}
}

void MeshBuilding::ColliderOff()
{
	
}

void MeshBuilding::ColliderOn()
{

}