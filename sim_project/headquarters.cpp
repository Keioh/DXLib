#include "headquarters.h"

void Headquarters::Init()
{
	headquarters_tab_active = -1;
	headquarters_tab_close.color = GetColor(255, 150, 150);
	key.init();

	headquarters_tab_close.Init();
	headquarters_button.Init();
}

void Headquarters::Load()
{
	headquarters_tab_close.Load("");
	headquarters_button.Load("pack/GameObject/models/test.png");
}

void Headquarters::DrawModel(VECTOR pos)//3Dモデルの描写
{
}

void Headquarters::Draw(int pos_x, int pos_y, Filer config, bool wire)
{
	key.GetKeyFrame();

	if (key.KeyCilick(KEY_INPUT_H) == true)
	{
		headquarters_tab_active *= -1;
	}

	if (headquarters_button.DrawButtonBox3D(wire) == true)
	{
		headquarters_tab_active *= -1;
	}
	SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

	Headquarters::DrawModel(VGet(0.0f, 0.0f, 0.0f));

	//タブがオンの時
	if (headquarters_tab_active == 1)
	{
		DrawBox(0, config.window_data.windowY / 4, config.window_data.windowX / 5, config.window_data.windowY, GetColor(200, 200, 200), TRUE);
		DrawFormatString(10, config.window_data.windowY / 4 + 10, GetColor(0, 0, 0), "%s", config.headquarters_infomation_basic.main_title);

		if (headquarters_tab_close.BoxUI_Button_BOX(config.window_data.windowX / 5 - 32, config.window_data.windowY / 4, 32, 32, 1, wire) == true)
		{
			headquarters_tab_active *= -1;
		}
	}


}
