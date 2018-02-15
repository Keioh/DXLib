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
	Key.GetKeyFrame();//�L�[�̐����ȓ��͂��\�ɂ��鏈���B

	if (infomation_tab_active_flag == 1)
	{
		SetDrawBright(255, 255, 255);//���̏��������Ȃ��Ɖ摜�\�����o�O��܂��B(��ʋP�x���ő�ɐݒ�)

		//���p�l���̔w�i
		//DrawBox(0, 0, 900, 600, GetColor(200, 200, 200), TRUE);


		if (faction_tab.Draw(0, 0, wire) == true)
		{
			infomation_tab_active_flag *= -1;
		}


		FactionInformation::DrawFactionStrings(config);//�����̕\��
	}

	//F�L�[����������^�u���I���ɂ���B
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
		//����
		//�^�u�̃^�C�g���������\��
		DrawFormatString(0 + 150, 0 + 20, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.main_title);

		//�^�u�̎x���_�������\��
		DrawFormatString(0 + 10, 0 + 150, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.branch_point);

		//�^�u�̌������������\��
		DrawFormatString(0 + 10, 0 + 210, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.laboratory);

		//�^�u�̎����������\��
		DrawFormatString(0 + 10, 0 + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.money);

		//�^�u�̌������������\��
		DrawFormatString(0 + 10, 0 + 330, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.research);

		//�^�u�̕׋����������\��
		DrawFormatString(0 + 10, 0 + 390, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.study);

		//�^�u�̓����������\��
		DrawFormatString(0 + 10, 0 + 450, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.characteristic);

		//�^�u�̎���u���b�N�������\��
		DrawFormatString(0 + 10, 0 + 510, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.block);


		//����
		//�^�u�̋G�ߕ������\��
		DrawFormatString(0 + 500, 0 + 60, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.seasons);

		//�^�u�̐ߋG�������\��
		DrawFormatString(0 + 500, 0 + 130, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.small_seasons);

		//�^�u�̔N�����������\��
		DrawFormatString(0 + 500, 0 + 200, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.years);

		//�^�u�̓G�Ε������\��
		DrawFormatString(0 + 500, 0 + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.hostility);

		//�^�u�̗F�D�������\��
		DrawFormatString(0 + 500, 0 + 340, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.friendship);

		//�^�u�̓����������\��
		DrawFormatString(0 + 500, 0 + 420, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.alliance);

		//�^�u�̎���������\��
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