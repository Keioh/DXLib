#include "data/game_data/UI/command_ui.h"

void CommandUI::Load()
{
	//�J���{�^���摜�̓ǂݍ���
	development_button.SwitchButtonBOX_Load("texter/game/command_button/development.png", 128, 64);

	//�����{�^���摜�̓ǂݍ���
	research_button.SwitchButtonBOX_Load("texter/game/command_button/research.png", 128, 64);

	//����{�^���摜�̓ǂݍ���
	policy_button.SwitchButtonBOX_Load("texter/game/command_button/policy.png", 128, 64);

	//�h�q�{�^���摜�̓ǂݍ���
	defense_button.SwitchButtonBOX_Load("texter/game/command_button/defense.png", 128, 64);

	//���{�^���摜�̓ǂݍ���
	information_button.SwitchButtonBOX_Load("texter/game/command_button/information.png", 128, 64);
}

void CommandUI::Init(VECTOR position)
{
	//�J���{�^���֘A
	development_button.SwitchButtonBOX_Init(VGet(0, 100, 0), VGet(128, 64, 0), "development_button");

	//�����{�^���֘A
	research_button.SwitchButtonBOX_Init(VGet(0, 100 + (64), 0), VGet(128, 64, 0), "research_button");

	//����{�^���֘A
	policy_button.SwitchButtonBOX_Init(VGet(0, 100 + (64 * 2), 0), VGet(128, 64, 0), "policy_button");

	//�h�q�{�^���֘A
	defense_button.SwitchButtonBOX_Init(VGet(0, 100 + (64 * 3), 0), VGet(128, 64, 0), "defense_button");

	//���{�^���֘A
	information_button.SwitchButtonBOX_Init(VGet(0, 100 + (64 * 4), 0), VGet(128, 64, 0), "information_button");

}

void CommandUI::Push(DiploidEngineImpact& impact)
{
	development_button.SwitchButtonBOX_Push(impact);
	research_button.SwitchButtonBOX_Push(impact);
	policy_button.SwitchButtonBOX_Push(impact);
	defense_button.SwitchButtonBOX_Push(impact);
	information_button.SwitchButtonBOX_Push(impact);

}

void CommandUI::Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//�J���{�^���A�b�v�f�[�g
	if (development_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}

	//�����{�^���A�b�v�f�[�g
	if (research_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//���̃{�^�����I�t�ɂ���
		development_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}

	//����{�^���A�b�v�f�[�g
	if (policy_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}

	//�h�q�{�^���A�b�v�f�[�g
	if (defense_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}

	//���{�^���A�b�v�f�[�g
	if (information_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
	}
}

void CommandUI::Draw(bool draw)
{
	if (draw == true)
	{
		development_button.SwitchButtonBOX_Draw();//�J���{�^���̕`��
		research_button.SwitchButtonBOX_Draw();//�����{�^���̕`��
		policy_button.SwitchButtonBOX_Draw();//����{�^���̕`��
		defense_button.SwitchButtonBOX_Draw();//�h�q�{�^���̕`��
		information_button.SwitchButtonBOX_Draw();//���{�^���̕`��
	}
}