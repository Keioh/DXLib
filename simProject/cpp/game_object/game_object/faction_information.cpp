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
	branch_point_window.Draw(pos_x + 10, pos_y + 150, config.faction_infomaiton_basic.branch_point, config.faction_tab_instructions.branch_point, wire);

	//研究所
	laboratory_window.Draw(pos_x + 10, pos_y + 210, config.faction_infomaiton_basic.laboratory, config.faction_tab_instructions.laboratory, wire);

	//お金
	money_window.Draw(pos_x + 10, pos_y + 270, config.faction_infomaiton_basic.money, config.faction_tab_instructions.money, wire);

	//研究中
	research_window.Draw(pos_x + 10, pos_y + 330, config.faction_infomaiton_basic.research, config.faction_tab_instructions.research, wire);

	//勉強中
	study_window.Draw(pos_x + 10, pos_y + 390, config.faction_infomaiton_basic.study, config.faction_tab_instructions.study, wire);

	//特性
	characteristic_window.Draw(pos_x + 10, pos_y + 450, config.faction_infomaiton_basic.characteristic, config.faction_tab_instructions.characteristic, wire);

	//取引停止
	block_window.Draw(pos_x + 10, pos_y + 510, config.faction_infomaiton_basic.block, config.faction_tab_instructions.block, wire);

	//季節
	seasons_window.Draw(pos_x + 500, pos_y + 60, config.faction_infomaiton_basic.seasons, config.faction_tab_instructions.seasons, wire);

	//節季
	small_seasons_window.Draw(pos_x + 500, pos_y + 130, config.faction_infomaiton_basic.small_seasons, config.faction_tab_instructions.small_seasons, wire);

	//年月日
	years_window.Draw(pos_x + 500, pos_y + 200, config.faction_infomaiton_basic.years, config.faction_tab_instructions.years, wire);

	//敵対
	hostility_window.Draw(pos_x + 500, pos_y + 270, config.faction_infomaiton_basic.hostility, config.faction_tab_instructions.hostility, wire);

	//友好
	friendship_window.Draw(pos_x + 500, pos_y + 340, config.faction_infomaiton_basic.friendship, config.faction_tab_instructions.friendship, wire);

	//友好
	alliance_window.Draw(pos_x + 500, pos_y + 420, config.faction_infomaiton_basic.alliance, config.faction_tab_instructions.alliance, wire);

	//取引
	transaction_window.Draw(pos_x + 500, pos_y + 500, config.faction_infomaiton_basic.transaction, config.faction_tab_instructions.transaction, wire);

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

	branch_point_window.ColliderOff();
	laboratory_window.ColliderOff();
	money_window.ColliderOff();
	research_window.ColliderOff();
	study_window.ColliderOff();
	characteristic_window.ColliderOff();
	block_window.ColliderOff();

	seasons_window.ColliderOff();
	small_seasons_window.ColliderOff();
	years_window.ColliderOff();
	hostility_window.ColliderOff();
	friendship_window.ColliderOff();
	alliance_window.ColliderOff();
	transaction_window.ColliderOff();
}

void FactionInformation::CollisionOn()
{
	faction_box.ColliderOn();
	faction_tab.infomation_tab_close.ColliderOn();

	branch_point_window.ColliderOn();
	laboratory_window.ColliderOn();
	money_window.ColliderOn();
	research_window.ColliderOn();
	study_window.ColliderOn();
	characteristic_window.ColliderOn();
	block_window.ColliderOn();

	seasons_window.ColliderOn();
	small_seasons_window.ColliderOn();
	years_window.ColliderOn();
	hostility_window.ColliderOn();
	friendship_window.ColliderOn();
	alliance_window.ColliderOn();
	transaction_window.ColliderOn();
}

void FactionInformation::FactionInfomationTabOff()
{
	if (infomation_tab_active_flag == 1)
	{
		infomation_tab_active_flag *= -1;
	}
}