#include "data/game_data/UI/command_ui.h"

void CommandUI::Load()
{
	//����{�^���摜�̓ǂݍ���
	production_button.SwitchButtonBOX_Load("texter/game/command_button/production.png", 128, 64);

	//�����{�^���摜�̓ǂݍ���
	research_button.SwitchButtonBOX_Load("texter/game/command_button/research.png", 128, 64);

	//�������{�^���摜�̓ǂݍ���
	shopping_button.SwitchButtonBOX_Load("texter/game/command_button/shopping.png", 128, 64);

	//��c�{�^���摜�̓ǂݍ���
	camp_button.SwitchButtonBOX_Load("texter/game/command_button/camp.png", 128, 64);

	//���{�^���摜�̓ǂݍ���
	information_button.SwitchButtonBOX_Load("texter/game/command_button/information.png", 128, 64);

	//�T���{�^���摜�̓ǂݍ���
	explore_button.SwitchButtonBOX_Load("texter/game/command_button/explore.png", 128, 64);

	//�ړ��{�^���摜�̓ǂݍ���
	move_button.SwitchButtonBOX_Load("texter/game/command_button/move.png", 128, 64);

}

void CommandUI::Init(VECTOR position)
{
	//����{�^���֘A
	production_button.SwitchButtonBOX_Init(VGet(position.x, position.y, 0), VGet(128, 64, 0), "production_button", DIPLOID_LAYER_00);

	//�����{�^���֘A
	research_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64), 0), VGet(128, 64, 0), "research_button", DIPLOID_LAYER_00);

	//�������{�^���֘A
	shopping_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 2), 0), VGet(128, 64, 0), "shopping_button", DIPLOID_LAYER_00);

	//��c�{�^���֘A
	camp_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 3), 0), VGet(128, 64, 0), "camp_button", DIPLOID_LAYER_00);

	//���{�^���֘A
	information_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 4), 0), VGet(128, 64, 0), "information_button", DIPLOID_LAYER_00);

	//�T���{�^���֘A
	explore_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 5), 0), VGet(128, 64, 0), "explore_button", DIPLOID_LAYER_00);

	//�ړ��{�^���֘A
	move_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 6), 0), VGet(128, 64, 0), "move_button", DIPLOID_LAYER_00);

}

void CommandUI::Push(DiploidEngineImpact& impact)
{
	//��v�{�^�����v�b�V��
	production_button.SwitchButtonBOX_Push(impact);
	research_button.SwitchButtonBOX_Push(impact);
	shopping_button.SwitchButtonBOX_Push(impact);
	camp_button.SwitchButtonBOX_Push(impact);
	information_button.SwitchButtonBOX_Push(impact);
	explore_button.SwitchButtonBOX_Push(impact);
	move_button.SwitchButtonBOX_Push(impact);
}

void CommandUI::Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//����{�^���A�b�v�f�[�g
	if (production_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = PRODUCTION_COMMAND;

		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//�����{�^���A�b�v�f�[�g
	if (research_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = RESEARCH_COMMAND;

		//���̃{�^�����I�t�ɂ���
		production_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//�������{�^���A�b�v�f�[�g
	if (shopping_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = SHOPPING_COMMAND;

		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//��c�{�^���A�b�v�f�[�g
	if (camp_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = CAMP_COMMAND;

		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//���{�^���A�b�v�f�[�g
	if (information_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = INFORMATION_COMMAND;

		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//�T���{�^���A�b�v�f�[�g
	if (explore_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = EXPLORE_COMMAND;

		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//�ړ��{�^���A�b�v�f�[�g
	if (move_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = MOVE_COMMAND;

		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
	}

	//�ǂ̃R�}���h��������Ă��Ȃ��u��
	if ((production_button.GetSwitchButton_Flag() == false) &&
		(research_button.GetSwitchButton_Flag() == false) &&
		(shopping_button.GetSwitchButton_Flag() == false) &&
		(camp_button.GetSwitchButton_Flag() == false) &&
		(information_button.GetSwitchButton_Flag() == false) &&
		(explore_button.GetSwitchButton_Flag() == false) &&
		(move_button.GetSwitchButton_Flag() == false))
	{
		select_command = NO_COMMAND;
	}
}

void CommandUI::Draw(bool draw)
{
	if (draw == true)
	{
		production_button.SwitchButtonBOX_Draw();//����{�^���̕`��
		research_button.SwitchButtonBOX_Draw();//�����{�^���̕`��
		shopping_button.SwitchButtonBOX_Draw();//�������{�^���̕`��
		camp_button.SwitchButtonBOX_Draw();//��c�{�^���̕`��
		information_button.SwitchButtonBOX_Draw();//���{�^���̕`��
		explore_button.SwitchButtonBOX_Draw();//���{�^���̕`��
		move_button.SwitchButtonBOX_Draw();//�ړ��{�^���̕`��
	}
}


int CommandUI::GetCommand()
{
	return select_command;
}