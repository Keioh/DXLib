#include "headquarters.h"

void Headquarters::Init()
{
	headquarters_tab_active = -1;
	headquarters_tab_close.color = GetColor(255, 150, 150);
	key.init();

	headquarters_tab.Init();
	headquarters_button.Init();
}

void Headquarters::Load()
{
	headquarters_tab.Load("pack/GameObject/GameUI/HQ_window/HQ_back_wall.png");
	headquarters_button.Load("pack/GameObject/models/hq.png");
}

void Headquarters::ColliderOff()
{
	headquarters_button.ColliderOff();
	headquarters_tab.infomation_tab_close.ColliderOff();
}

void Headquarters::ColliderOn()
{
	headquarters_button.ColliderOn();
	headquarters_tab.infomation_tab_close.ColliderOn();
}

void Headquarters::Transform(VECTOR scale, float rotate_x, float rotate_y, float rotate_z, VECTOR trans)//3Dモデルの描写
{
	headquarters_button.Transform(scale, rotate_x, rotate_y, rotate_z, trans);
}

void Headquarters::ObjectDraw(int pos_x, int pos_y, Filer config, bool wire)
{
	key.GetKeyFrame();

	if (key.KeyCilick(KEY_INPUT_H) == true)
	{
		headquarters_tab_active *= -1;
	}

	if (headquarters_button.DrawButtonBox3D(wire) == true)//オブジェクト表示とクリック判定
	{
		headquarters_tab_active *= -1;
	}
}

void Headquarters::TabDraw(Filer config, bool wire)
{
	//タブがオンの時
	if (headquarters_tab_active == 1)
	{
		if (headquarters_tab.Draw(0, config.window_data.windowY - headquarters_tab.graphics_size_y, wire) == true)
		{
			headquarters_tab_active *= -1;
		}
		//DrawBox(0, config.window_data.windowY / 4, config.window_data.windowX / 5, config.window_data.windowY, GetColor(200, 200, 200), TRUE);
		DrawFormatString(20, config.window_data.windowY - headquarters_tab.graphics_size_y + 20, GetColor(0, 0, 0), "%s", config.headquarters_infomation_basic.main_title);

	}
}