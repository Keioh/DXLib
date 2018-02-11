#include "faction_information.h"

void FactionInformation::Init()
{
	faction_circle.Init();
	infomation_tab_close.Init();

	infomation_tab_close.color = GetColor(255, 150, 150);
}

void FactionInformation::Load()
{
	faction_circle.Load("pack/GameObject/faction/blue_faction.png");
	infomation_tab_close.Load("");
}

void FactionInformation::Draw(int pos_x, int pos_y, Filer config, bool wire)
{
	SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

	if (faction_circle.CircleUI_Button(pos_x, pos_y, 115, 1, wire) == true)
	{
		infomation_tab_active_flag *= -1;
	}

	if (infomation_tab_active_flag == 1)
	{
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

		//情報パネルの背景
		DrawBox(config.window_data.windowX / 5, config.window_data.windowY / 6, config.window_data.windowX - config.window_data.windowX / 5, config.window_data.windowY - config.window_data.windowY / 6, GetColor(200, 200, 200), TRUE);

		//一列目
		//タブのタイトル文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 10, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.main_title);

		//タブの支拠点文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 60, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.branch_point);

		//タブの研究所文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 130, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.laboratory);

		//タブの資金文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 200, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.money);

		//タブの研究中文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.research);

		//タブの勉強中文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 340, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.study);


		//二列目
		//タブの季節文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 60, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.seasons);

		//タブの節季文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 130, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.small_seasons);

		//タブの年月日文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 200, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.years);

		//タブの敵対文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.hostility);

		//タブの友好文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 340, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.friendship);

		//タブの同盟文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 420, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.alliance);

		//タブの取引文字列を表示
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 500, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.transaction);

		//情報パネルを閉じるボタン
		if (infomation_tab_close.BoxUI_Button_BOX(config.window_data.windowX - config.window_data.windowX / 5 - 32, config.window_data.windowY / 6, 32, 32, 1, wire) == true)
		{
			infomation_tab_active_flag *= -1;
		}
	}
}

void FactionInformation::CollisionOff()
{
	faction_circle.circle_collision.active = false;
	infomation_tab_close.box_collision.active = false;
}