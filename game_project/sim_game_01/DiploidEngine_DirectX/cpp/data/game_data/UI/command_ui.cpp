#include "data/game_data/UI/command_ui.h"

void CommandUI::Load()
{
	//製作ボタン画像の読み込み
	production_button.SwitchButtonBOX_Load("texter/game/command_button/production.png", 128, 64);

	//研究ボタン画像の読み込み
	research_button.SwitchButtonBOX_Load("texter/game/command_button/research.png", 128, 64);

	//買い物ボタン画像の読み込み
	shopping_button.SwitchButtonBOX_Load("texter/game/command_button/shopping.png", 128, 64);

	//野営ボタン画像の読み込み
	camp_button.SwitchButtonBOX_Load("texter/game/command_button/camp.png", 128, 64);

	//情報ボタン画像の読み込み
	information_button.SwitchButtonBOX_Load("texter/game/command_button/information.png", 128, 64);

	//探索ボタン画像の読み込み
	explore_button.SwitchButtonBOX_Load("texter/game/command_button/explore.png", 128, 64);

	//移動ボタン画像の読み込み
	move_button.SwitchButtonBOX_Load("texter/game/command_button/move.png", 128, 64);

}

void CommandUI::Init(VECTOR position)
{
	//製作ボタン関連
	production_button.SwitchButtonBOX_Init(VGet(position.x, position.y, 0), VGet(128, 64, 0), "production_button", DIPLOID_LAYER_00);

	//研究ボタン関連
	research_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64), 0), VGet(128, 64, 0), "research_button", DIPLOID_LAYER_00);

	//買い物ボタン関連
	shopping_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 2), 0), VGet(128, 64, 0), "shopping_button", DIPLOID_LAYER_00);

	//野営ボタン関連
	camp_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 3), 0), VGet(128, 64, 0), "camp_button", DIPLOID_LAYER_00);

	//情報ボタン関連
	information_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 4), 0), VGet(128, 64, 0), "information_button", DIPLOID_LAYER_00);

	//探索ボタン関連
	explore_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 5), 0), VGet(128, 64, 0), "explore_button", DIPLOID_LAYER_00);

	//移動ボタン関連
	move_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 6), 0), VGet(128, 64, 0), "move_button", DIPLOID_LAYER_00);

}

void CommandUI::Push(DiploidEngineImpact& impact)
{
	//主要ボタンをプッシュ
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
	//製作ボタンアップデート
	if (production_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = PRODUCTION_COMMAND;

		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//研究ボタンアップデート
	if (research_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = RESEARCH_COMMAND;

		//他のボタンをオフにする
		production_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//買い物ボタンアップデート
	if (shopping_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = SHOPPING_COMMAND;

		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//野営ボタンアップデート
	if (camp_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = CAMP_COMMAND;

		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//情報ボタンアップデート
	if (information_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = INFORMATION_COMMAND;

		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//探索ボタンアップデート
	if (explore_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = EXPLORE_COMMAND;

		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		move_button.SwitchButton_Flag_Change(false);
	}

	//移動ボタンアップデート
	if (move_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		select_command = MOVE_COMMAND;

		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		shopping_button.SwitchButton_Flag_Change(false);
		camp_button.SwitchButton_Flag_Change(false);
		production_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
		explore_button.SwitchButton_Flag_Change(false);
	}

	//どのコマンドも押されていない置き
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
		production_button.SwitchButtonBOX_Draw();//製作ボタンの描写
		research_button.SwitchButtonBOX_Draw();//研究ボタンの描写
		shopping_button.SwitchButtonBOX_Draw();//買い物ボタンの描写
		camp_button.SwitchButtonBOX_Draw();//野営ボタンの描写
		information_button.SwitchButtonBOX_Draw();//情報ボタンの描写
		explore_button.SwitchButtonBOX_Draw();//情報ボタンの描写
		move_button.SwitchButtonBOX_Draw();//移動ボタンの描写
	}
}


int CommandUI::GetCommand()
{
	return select_command;
}