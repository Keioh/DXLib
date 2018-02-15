#include "faction_information.h"

void FactionInformation::Init()
{
	Key.init();
	faction_box.Init();
	faction_tab.Init();
}

void FactionInformation::Load()
{
	faction_tab.Load("pack/GameObject/GameUI/faction_window/faction_back_wall.png");
	faction_box.Load("pack/GameObject/faction/blue_faction.png");
}

void FactionInformation::Draw(int pos_x, int pos_y, Filer config, bool wire)
{
	Key.GetKeyFrame();//キーの精密な入力を可能にする処理。

	if (infomation_tab_active_flag == 1)
	{
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

		//情報パネルの背景
		//DrawBox(0, 0, 900, 600, GetColor(200, 200, 200), TRUE);


		if (faction_tab.Draw(0, 0, wire) == true)
		{
			infomation_tab_active_flag *= -1;
		}


		FactionInformation::DrawFactionStrings(config);//文字の表示
	}

	//Fキーを押したらタブをオンにする。
	if (Key.KeyCilick(KEY_INPUT_F) == true)
	{
		infomation_tab_active_flag *= -1;
	}

	if (faction_box.BoxUI_Button(pos_x, pos_y, 1, wire) == true)
	{
		infomation_tab_active_flag *= -1;
	}
}

void FactionInformation::DrawFactionStrings(Filer config)
{
		//一列目
		//タブのタイトル文字列を表示
		DrawFormatString(0 + 150, 0 + 20, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.main_title);

		//タブの支拠点文字列を表示
		DrawFormatString(0 + 10, 0 + 150, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.branch_point);

		//タブの研究所文字列を表示
		DrawFormatString(0 + 10, 0 + 210, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.laboratory);

		//タブの資金文字列を表示
		DrawFormatString(0 + 10, 0 + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.money);

		//タブの研究中文字列を表示
		DrawFormatString(0 + 10, 0 + 330, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.research);

		//タブの勉強中文字列を表示
		DrawFormatString(0 + 10, 0 + 390, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.study);

		//タブの特性文字列を表示
		DrawFormatString(0 + 10, 0 + 450, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.characteristic);

		//タブの取引ブロック文字列を表示
		DrawFormatString(0 + 10, 0 + 510, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.block);


		//二列目
		//タブの季節文字列を表示
		DrawFormatString(0 + 500, 0 + 60, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.seasons);

		//タブの節季文字列を表示
		DrawFormatString(0 + 500, 0 + 130, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.small_seasons);

		//タブの年月日文字列を表示
		DrawFormatString(0 + 500, 0 + 200, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.years);

		//タブの敵対文字列を表示
		DrawFormatString(0 + 500, 0 + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.hostility);

		//タブの友好文字列を表示
		DrawFormatString(0 + 500, 0 + 340, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.friendship);

		//タブの同盟文字列を表示
		DrawFormatString(0 + 500, 0 + 420, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.alliance);

		//タブの取引文字列を表示
		DrawFormatString(0 + 500, 0 + 500, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.transaction);
}

void FactionInformation::CollisionOff()
{
	faction_box.ColliderOff();
	faction_tab.infomation_tab_close.ColliderOff();
}

void FactionInformation::CollisionOn()
{
	faction_box.ColliderOn();
	faction_tab.infomation_tab_close.ColliderOn();
}

void FactionInformation::FactionInfomationTabOff()
{
	if (infomation_tab_active_flag == 1)
	{
		infomation_tab_active_flag *= -1;
	}
}