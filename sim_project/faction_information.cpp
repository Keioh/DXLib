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

void FactionInformation::Instructions(int pos_x, int pos_y, Filer config, bool wire)
{
	//支拠点
	if (branch_point_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.branch_point) * 8, pos_y + 150, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(branch_point_collision.x + 10, branch_point_collision.y + 10, branch_point_collision.x + strlen(config.faction_tab_instructions.branch_point) * 9, branch_point_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(branch_point_collision.x + 20, branch_point_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.branch_point);
	}

	//研究所
	if (laboratory_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.branch_point) * 8, pos_y + 210, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(laboratory_collision.x + 10, laboratory_collision.y + 10, laboratory_collision.x + strlen(config.faction_tab_instructions.laboratory) * 9, laboratory_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(laboratory_collision.x + 20, laboratory_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.laboratory);
	}
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


		FactionInformation::DrawFactionStrings(pos_x, pos_y, config);//文字の表示

		FactionInformation::Instructions(pos_x, pos_y, config, wire);//カーソルを合わせた際の詳細説明表示
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

void FactionInformation::DrawFactionStrings(int pos_x, int pos_y, Filer config)
{
		//一列目
		//タブのタイトル文字列を表示
		DrawFormatString(pos_x + 150, pos_y + 20, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.main_title);

		//タブの支拠点文字列を表示
		DrawFormatString(pos_x + 10, pos_y + 150, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.branch_point);

		//タブの研究所文字列を表示
		DrawFormatString(pos_x + 10, pos_y + 210, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.laboratory);

		//タブの資金文字列を表示
		DrawFormatString(pos_x + 10, pos_y + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.money);

		//タブの研究中文字列を表示
		DrawFormatString(pos_x + 10, pos_y + 330, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.research);

		//タブの勉強中文字列を表示
		DrawFormatString(pos_x + 10, pos_y + 390, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.study);

		//タブの特性文字列を表示
		DrawFormatString(pos_x + 10, pos_y + 450, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.characteristic);

		//タブの取引ブロック文字列を表示
		DrawFormatString(pos_x + 10, pos_y + 510, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.block);


		//二列目
		//タブの季節文字列を表示
		DrawFormatString(pos_x + 500, pos_y + 60, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.seasons);

		//タブの節季文字列を表示
		DrawFormatString(pos_x + 500, pos_y + 130, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.small_seasons);

		//タブの年月日文字列を表示
		DrawFormatString(pos_x + 500, pos_y + 200, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.years);

		//タブの敵対文字列を表示
		DrawFormatString(pos_x + 500, pos_y + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.hostility);

		//タブの友好文字列を表示
		DrawFormatString(pos_x + 500, pos_y + 340, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.friendship);

		//タブの同盟文字列を表示
		DrawFormatString(pos_x + 500, pos_y + 420, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.alliance);

		//タブの取引文字列を表示
		DrawFormatString(pos_x + 500, pos_y + 500, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.transaction);
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