#include "mesh_building.h"

void MeshBuilding::Init()
{
	window.Init();
	building0.Init();
	building1.Init();
	building2.Init();
	building_type = 0;

	//test
	building0_money = building1_money = building2_money = 1000;
	building0_time = building1_time = building2_time = 7;
	market_place_button.color = GetColor(255, 100, 100);
	laboratory_button.color = GetColor(100, 100, 255);
	empty_lot_button.color = GetColor(100, 100, 100);
}

void MeshBuilding::Load()
{
	lock_graphics = LoadGraph("pack/GameObject/GameUI/sub/lock.png");
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
			object_click = 1;
		}
		else
		{
			object_click = 0;
		}
	}
	else if (building_type == 1)//建物タイプが交易所(1)なら
	{
		building1.Mode(mode);
		building1.Draw(wire);

		if (building1.object_click == true)
		{
			window_flag *= -1;
			object_click = 1;
		}
		else
		{
			object_click = 0;
		}
	}
	else if (building_type == 2)//建物タイプが研究所(2)なら
	{
		building2.Mode(mode);
		building2.Draw(wire);

		if (building2.object_click == true)
		{
			window_flag *= -1;
			object_click = 1;
		}
		else
		{
			object_click = 0;
		}
	}
}

void MeshBuilding::DrawUI(int window_x, int window_y, MODE mode, Filer config, bool wire)
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

		//交易所にするボタン
		if ((market_place_button.BoxUI_Button_BOX(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 50, 100, 50, 1, wire) == 1) && (building_type != 1))
		{
			building_type = 1;
		}

		//研究所にするボタン
		if ((laboratory_button.BoxUI_Button_BOX(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 150, 100, 50, 1, wire) == 1) && (building_type != 2))
		{
			building_type = 2;
		}

		//更地にするボタン
		if ((empty_lot_button.BoxUI_Button_BOX(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 250, 100, 50, 1, wire) == 1) && (building_type != 0))
		{
			building_type = 0;
		}

		//建物が建っていたらLOCK画像を表示
		if (building_type == 1)DrawGraph(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 50, lock_graphics, TRUE);
		if (building_type == 2)DrawGraph(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 150, lock_graphics, TRUE);
		if (building_type == 0)DrawGraph(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 250, lock_graphics, TRUE);

		DrawStirngUI(window_x, window_y, config);//文字を表示
	}

	//接続モードがオンの時のUI表示
	if (mode.connection_mode == 1)
	{

	}
}

void MeshBuilding::DrawStirngUI(int window_x, int window_y, Filer config)
{
	//タブ情報
	DrawFormatString(window_x - window.graphics_size_x + 100, window_y - window.graphics_size_y + 10, GetColor(0, 0, 0), "%s", config.building_infomaiton_basic.main_title);

	//建設ボタン関連
	DrawFormatString(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 30, GetColor(0, 0, 0), "%s", config.building_infomaiton_basic.construction);
	DrawFormatString(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 50, GetColor(0, 0, 0), "%s", config.building_infomaiton_basic.market_place);
	DrawFormatString(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 150, GetColor(0, 0, 0), "%s", config.building_infomaiton_basic.labolatry);
	DrawFormatString(window_x - window.graphics_size_x + 20, window_y - window.graphics_size_y + 250, GetColor(0, 0, 0), "%s", config.building_infomaiton_basic.empty_lot);

	//建設にかかるお金と時間
	DrawFormatString(window_x - window.graphics_size_x + 130, window_y - window.graphics_size_y + 50, GetColor(0, 0, 0), "%d cash", building0_money);
	DrawFormatString(window_x - window.graphics_size_x + 130, window_y - window.graphics_size_y + 80, GetColor(0, 0, 0), "%d day", building0_time);

	DrawFormatString(window_x - window.graphics_size_x + 130, window_y - window.graphics_size_y + 150, GetColor(0, 0, 0), "%d cash", building1_money);
	DrawFormatString(window_x - window.graphics_size_x + 130, window_y - window.graphics_size_y + 180, GetColor(0, 0, 0), "%d day", building1_time);

	DrawFormatString(window_x - window.graphics_size_x + 130, window_y - window.graphics_size_y + 250, GetColor(0, 0, 0), "%d cash", building2_money);
	DrawFormatString(window_x - window.graphics_size_x + 130, window_y - window.graphics_size_y + 280, GetColor(0, 0, 0), "%d day", building2_time);
}

void MeshBuilding::ColliderOff()
{
	
}

void MeshBuilding::ColliderOn()
{

}