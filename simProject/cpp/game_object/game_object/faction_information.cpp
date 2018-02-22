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
	//�x���_
	if (branch_point_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.branch_point) * 8, pos_y + 150, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(branch_point_collision.x + 10, branch_point_collision.y + 10, branch_point_collision.x + strlen(config.faction_tab_instructions.branch_point) * 9, branch_point_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(branch_point_collision.x + 20, branch_point_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.branch_point);
	}

	//������
	if (laboratory_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.branch_point) * 8, pos_y + 210, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(laboratory_collision.x + 10, laboratory_collision.y + 10, laboratory_collision.x + strlen(config.faction_tab_instructions.laboratory) * 9, laboratory_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(laboratory_collision.x + 20, laboratory_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.laboratory);
	}

	//����
	if (money_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.money) * 8, pos_y + 270, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(money_collision.x + 10, money_collision.y + 10, money_collision.x + strlen(config.faction_tab_instructions.money) * 9, money_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(money_collision.x + 20, money_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.money);
	}

	//������
	if (research_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.research) * 8, pos_y + 330, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(research_collision.x + 10, research_collision.y + 10, research_collision.x + strlen(config.faction_tab_instructions.research) * 9, research_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(research_collision.x + 20, research_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.research);
	}

	//�׋���
	if (study_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.study) * 8, pos_y + 390, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(study_collision.x + 10, study_collision.y + 10, study_collision.x + strlen(config.faction_tab_instructions.study) * 9, study_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(study_collision.x + 20, study_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.study);
	}

	//����
	if (characteristic_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.characteristic) * 8, pos_y + 450, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(characteristic_collision.x + 10, characteristic_collision.y + 10, characteristic_collision.x + strlen(config.faction_tab_instructions.characteristic) * 9, characteristic_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(characteristic_collision.x + 20, characteristic_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.characteristic);
	}

	//�����~
	if (block_collision.BoxColliderMouse(pos_x + 10, strlen(config.faction_infomaiton_basic.block) * 8, pos_y + 510, 20, wire) == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(block_collision.x + 10, block_collision.y + 10, block_collision.x + strlen(config.faction_tab_instructions.block) * 9, block_collision.y + 50, GetColor(100, 100, 100), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawFormatString(block_collision.x + 20, block_collision.y + 20, GetColor(0, 0, 0), "%s", config.faction_tab_instructions.block);
	}

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


		FactionInformation::DrawFactionStrings(pos_x, pos_y, config);//�����̕\��

		FactionInformation::Instructions(pos_x, pos_y, config, wire);//�J�[�\�������킹���ۂ̏ڍא����\��
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

void FactionInformation::DrawFactionStrings(int pos_x, int pos_y, Filer config)
{
		//����
		//�^�u�̃^�C�g���������\��
		DrawFormatString(pos_x + 150, pos_y + 20, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.main_title);

		//�^�u�̎x���_�������\��
		DrawFormatString(pos_x + 10, pos_y + 150, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.branch_point);

		//�^�u�̌������������\��
		DrawFormatString(pos_x + 10, pos_y + 210, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.laboratory);

		//�^�u�̎����������\��
		DrawFormatString(pos_x + 10, pos_y + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.money);

		//�^�u�̌������������\��
		DrawFormatString(pos_x + 10, pos_y + 330, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.research);

		//�^�u�̕׋����������\��
		DrawFormatString(pos_x + 10, pos_y + 390, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.study);

		//�^�u�̓����������\��
		DrawFormatString(pos_x + 10, pos_y + 450, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.characteristic);

		//�^�u�̎���u���b�N�������\��
		DrawFormatString(pos_x + 10, pos_y + 510, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.block);


		//����
		//�^�u�̋G�ߕ������\��
		DrawFormatString(pos_x + 500, pos_y + 60, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.seasons);

		//�^�u�̐ߋG�������\��
		DrawFormatString(pos_x + 500, pos_y + 130, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.small_seasons);

		//�^�u�̔N�����������\��
		DrawFormatString(pos_x + 500, pos_y + 200, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.years);

		//�^�u�̓G�Ε������\��
		DrawFormatString(pos_x + 500, pos_y + 270, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.hostility);

		//�^�u�̗F�D�������\��
		DrawFormatString(pos_x + 500, pos_y + 340, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.friendship);

		//�^�u�̓����������\��
		DrawFormatString(pos_x + 500, pos_y + 420, GetColor(0, 0, 0), "%s", config.faction_infomaiton_basic.alliance);

		//�^�u�̎���������\��
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