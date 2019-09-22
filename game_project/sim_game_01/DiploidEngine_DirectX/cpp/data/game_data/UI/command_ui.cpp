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



	//�_�ƃ{�^���摜�̓ǂݍ���
	agriculture_button.SwitchButtonBOX_Load("texter/game/command_button/agriculture.png", 112, 52);

	//�H�ƃ{�^���摜�̓ǂݍ���
	industrial_button.SwitchButtonBOX_Load("texter/game/command_button/industrial.png", 112, 52);

	//�Ȋw�{�^���摜�̓ǂݍ���
	science_button.SwitchButtonBOX_Load("texter/game/command_button/science.png", 112, 52);

}

void CommandUI::Init(VECTOR position)
{
	//�J���{�^���֘A
	development_button.SwitchButtonBOX_Init(VGet(position.x, position.y, 0), VGet(128, 64, 0), "development_button", DIPLOID_LAYER_01);

	//�����{�^���֘A
	research_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64), 0), VGet(128, 64, 0), "research_button", DIPLOID_LAYER_01);

	//����{�^���֘A
	policy_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 2), 0), VGet(128, 64, 0), "policy_button", DIPLOID_LAYER_01);

	//�h�q�{�^���֘A
	defense_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 3), 0), VGet(128, 64, 0), "defense_button", DIPLOID_LAYER_01);

	//���{�^���֘A
	information_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 4), 0), VGet(128, 64, 0), "information_button", DIPLOID_LAYER_01);



	//�_�ƃ{�^���֘A
	agriculture_button.SwitchButtonBOX_Init(VGet(position.x + (128), position.y, 0), VGet(112, 52, 0), "agriculture_button", DIPLOID_LAYER_01);

	//�H�ƃ{�^���֘A
	industrial_button.SwitchButtonBOX_Init(VGet(position.x + (128), position.y + (52), 0), VGet(112, 52, 0), "industrial_button", DIPLOID_LAYER_01);

	//�Ȋw�{�^���֘A
	science_button.SwitchButtonBOX_Init(VGet(position.x + (128), position.y + (52 * 2), 0), VGet(112, 52, 0), "science_button", DIPLOID_LAYER_01);

}

void CommandUI::Push(DiploidEngineImpact& impact)
{
	//��v�{�^�����v�b�V��
	development_button.SwitchButtonBOX_Push(impact);
	research_button.SwitchButtonBOX_Push(impact);
	policy_button.SwitchButtonBOX_Push(impact);
	defense_button.SwitchButtonBOX_Push(impact);
	information_button.SwitchButtonBOX_Push(impact);
}

void CommandUI::Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//�J���{�^���A�b�v�f�[�g
	if (development_button_flag = development_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//�_�ƃ{�^���̒ǉ�
		agriculture_button_systme.OnePushBOX_Impact(impact, agriculture_button.box);
		agriculture_button_systme.FlagReset_OneDeleteBOX();//�폜�t���O�̃��Z�b�g

		//�_�ƃ{�^���̃A�b�v�f�[�g
		if (agriculture_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
		{

			//���̃{�^�����I�t�ɂ���
			industrial_button.SwitchButton_Flag_Change(false);
			science_button.SwitchButton_Flag_Change(false);
		}


		//�H�ƃ{�^���̒ǉ�
		industrial_button_systme.OnePushBOX_Impact(impact, industrial_button.box);
		industrial_button_systme.FlagReset_OneDeleteBOX();//�폜�t���O�̃��Z�b�g

		//�H�ƃ{�^���̃A�b�v�f�[�g
		if (industrial_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
		{

			//���̃{�^�����I�t�ɂ���
			agriculture_button.SwitchButton_Flag_Change(false);
			science_button.SwitchButton_Flag_Change(false);
		}


		//�Ȋw�{�^���̒ǉ�
		science_button_system.OnePushBOX_Impact(impact, science_button.box);
		science_button_system.FlagReset_OneDeleteBOX();//�폜�t���O�̃��Z�b�g

		//�Ȋw�{�^���̃A�b�v�f�[�g
		if (science_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
		{

			//���̃{�^�����I�t�ɂ���
			agriculture_button.SwitchButton_Flag_Change(false);
			industrial_button.SwitchButton_Flag_Change(false);
		}


		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}
	else
	{
		//�_�ƃ{�^���̍폜
		if (agriculture_button_systme.GetOnePushBOX_Flag() == true)
		{
			agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
			agriculture_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g
		}

		//�H�ƃ{�^���̍폜
		if (industrial_button_systme.GetOnePushBOX_Flag() == true)
		{
			industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
			industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g
		}

		//�Ȋw�{�^���̍폜
		if (science_button_system.GetOnePushBOX_Flag() == true)
		{
			science_button_system.OneDeleteBOX_Impact(impact, "science_button");
			science_button_system.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g
		}
	}


	//�����{�^���A�b�v�f�[�g
	if (research_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//�_�ƃ{�^���̍폜
		agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
		agriculture_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g

		//�H�ƃ{�^���̍폜
		industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
		industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g

		//�Ȋw�{�^���̍폜
		industrial_button_systme.OneDeleteBOX_Impact(impact, "science_button");
		industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g


		//���̃{�^�����I�t�ɂ���
		development_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);

		industrial_button.SwitchButton_Flag_Change(false);
		science_button.SwitchButton_Flag_Change(false);
		agriculture_button.SwitchButton_Flag_Change(false);
	}

	//����{�^���A�b�v�f�[�g
	if (policy_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//�_�ƃ{�^���̍폜
		agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
		agriculture_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g

		//�H�ƃ{�^���̍폜
		industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
		industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g

		//�Ȋw�{�^���̍폜
		industrial_button_systme.OneDeleteBOX_Impact(impact, "science_button");
		industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g


		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);

		industrial_button.SwitchButton_Flag_Change(false);
		science_button.SwitchButton_Flag_Change(false);
		agriculture_button.SwitchButton_Flag_Change(false);
	}

	//�h�q�{�^���A�b�v�f�[�g
	if (defense_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//�_�ƃ{�^���̍폜
		agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
		agriculture_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g

		//�H�ƃ{�^���̍폜
		industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
		industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g

		//�Ȋw�{�^���̍폜
		industrial_button_systme.OneDeleteBOX_Impact(impact, "science_button");
		industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g


		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);

		industrial_button.SwitchButton_Flag_Change(false);
		science_button.SwitchButton_Flag_Change(false);
		agriculture_button.SwitchButton_Flag_Change(false);
	}

	//���{�^���A�b�v�f�[�g
	if (information_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//�_�ƃ{�^���̍폜
		agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
		agriculture_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g

		//�H�ƃ{�^���̍폜
		industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
		industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g

		//�Ȋw�{�^���̍폜
		industrial_button_systme.OneDeleteBOX_Impact(impact, "science_button");
		industrial_button_systme.FlagReset_OnePushBOX();//�v�b�V���t���O�̃��Z�b�g


		//���̃{�^�����I�t�ɂ���
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);

		industrial_button.SwitchButton_Flag_Change(false);
		science_button.SwitchButton_Flag_Change(false);
		agriculture_button.SwitchButton_Flag_Change(false);
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

		//�J���{�^�����I���̎�
		if (development_button_flag == true)
		{
			agriculture_button.SwitchButtonBOX_Draw();//�_�ƃ{�^���̕`��
			industrial_button.SwitchButtonBOX_Draw();//�H�ƃ{�^���̕`��
			science_button.SwitchButtonBOX_Draw();//�Ȋw�{�^���̕`��
		}
	}
}