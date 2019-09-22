#include "data/game_data/UI/command_ui.h"

void CommandUI::Load()
{
	//開発ボタン画像の読み込み
	development_button.SwitchButtonBOX_Load("texter/game/command_button/development.png", 128, 64);

	//研究ボタン画像の読み込み
	research_button.SwitchButtonBOX_Load("texter/game/command_button/research.png", 128, 64);

	//政策ボタン画像の読み込み
	policy_button.SwitchButtonBOX_Load("texter/game/command_button/policy.png", 128, 64);

	//防衛ボタン画像の読み込み
	defense_button.SwitchButtonBOX_Load("texter/game/command_button/defense.png", 128, 64);

	//情報ボタン画像の読み込み
	information_button.SwitchButtonBOX_Load("texter/game/command_button/information.png", 128, 64);
}

void CommandUI::Init(VECTOR position)
{
	//開発ボタン関連
	development_button.SwitchButtonBOX_Init(VGet(0, 100, 0), VGet(128, 64, 0), "development_button");

	//研究ボタン関連
	research_button.SwitchButtonBOX_Init(VGet(0, 100 + (64), 0), VGet(128, 64, 0), "research_button");

	//政策ボタン関連
	policy_button.SwitchButtonBOX_Init(VGet(0, 100 + (64 * 2), 0), VGet(128, 64, 0), "policy_button");

	//防衛ボタン関連
	defense_button.SwitchButtonBOX_Init(VGet(0, 100 + (64 * 3), 0), VGet(128, 64, 0), "defense_button");

	//情報ボタン関連
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
	//開発ボタンアップデート
	if (development_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}

	//研究ボタンアップデート
	if (research_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//他のボタンをオフにする
		development_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}

	//政策ボタンアップデート
	if (policy_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}

	//防衛ボタンアップデート
	if (defense_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}

	//情報ボタンアップデート
	if (information_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//他のボタンをオフにする
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
		development_button.SwitchButtonBOX_Draw();//開発ボタンの描写
		research_button.SwitchButtonBOX_Draw();//研究ボタンの描写
		policy_button.SwitchButtonBOX_Draw();//政策ボタンの描写
		defense_button.SwitchButtonBOX_Draw();//防衛ボタンの描写
		information_button.SwitchButtonBOX_Draw();//情報ボタンの描写
	}
}