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
	SetDrawBright(255, 255, 255);//���̏��������Ȃ��Ɖ摜�\�����o�O��܂��B(��ʋP�x���ő�ɐݒ�)

	if (faction_circle.CircleUI_Button(pos_x, pos_y, 115, 1, wire) == true)
	{
		infomation_tab_active_flag *= -1;
	}

	if (infomation_tab_active_flag == 1)
	{
		SetDrawBright(255, 255, 255);//���̏��������Ȃ��Ɖ摜�\�����o�O��܂��B(��ʋP�x���ő�ɐݒ�)

		//���p�l���̔w�i
		DrawBox(config.window_data.windowX / 5, config.window_data.windowY / 6, config.window_data.windowX - config.window_data.windowX / 5, config.window_data.windowY - config.window_data.windowY / 6, GetColor(200, 200, 200), TRUE);
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 10, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.main_title);
		//���p�l�������{�^��
		if (infomation_tab_close.BoxUI_Button_BOX(config.window_data.windowX - config.window_data.windowX / 5 - 32, config.window_data.windowY / 6, 32, 32, 1, wire) == true)
		{
			infomation_tab_active_flag *= -1;
		}
	}
}

void FactionInformation::CollisionOff()
{
	faction_circle.circle_collision.active = false;
}