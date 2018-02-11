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

		//����
		//�^�u�̃^�C�g���������\��
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 10, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.main_title);

		//�^�u�̎x���_�������\��
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 60, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.branch_point);

		//�^�u�̌������������\��
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 130, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.laboratory);

		//�^�u�̎����������\��
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 200, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.money);

		//�^�u�̌������������\��
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.research);

		//�^�u�̕׋����������\��
		DrawFormatString(config.window_data.windowX / 5 + 10, config.window_data.windowY / 6 + 340, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.study);


		//����
		//�^�u�̋G�ߕ������\��
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 60, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.seasons);

		//�^�u�̐ߋG�������\��
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 130, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.small_seasons);

		//�^�u�̔N�����������\��
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 200, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.years);

		//�^�u�̓G�Ε������\��
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.hostility);

		//�^�u�̗F�D�������\��
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 340, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.friendship);

		//�^�u�̓����������\��
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 420, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.alliance);

		//�^�u�̎���������\��
		DrawFormatString(config.window_data.windowX / 5 + 500, config.window_data.windowY / 6 + 500, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.transaction);

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
	infomation_tab_close.box_collision.active = false;
}