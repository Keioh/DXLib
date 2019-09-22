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



	//農業ボタン画像の読み込み
	agriculture_button.SwitchButtonBOX_Load("texter/game/command_button/agriculture.png", 112, 52);

	//工業ボタン画像の読み込み
	industrial_button.SwitchButtonBOX_Load("texter/game/command_button/industrial.png", 112, 52);

	//科学ボタン画像の読み込み
	science_button.SwitchButtonBOX_Load("texter/game/command_button/science.png", 112, 52);

}

void CommandUI::Init(VECTOR position)
{
	//開発ボタン関連
	development_button.SwitchButtonBOX_Init(VGet(position.x, position.y, 0), VGet(128, 64, 0), "development_button", DIPLOID_LAYER_01);

	//研究ボタン関連
	research_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64), 0), VGet(128, 64, 0), "research_button", DIPLOID_LAYER_01);

	//政策ボタン関連
	policy_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 2), 0), VGet(128, 64, 0), "policy_button", DIPLOID_LAYER_01);

	//防衛ボタン関連
	defense_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 3), 0), VGet(128, 64, 0), "defense_button", DIPLOID_LAYER_01);

	//情報ボタン関連
	information_button.SwitchButtonBOX_Init(VGet(position.x, position.y + (64 * 4), 0), VGet(128, 64, 0), "information_button", DIPLOID_LAYER_01);



	//農業ボタン関連
	agriculture_button.SwitchButtonBOX_Init(VGet(position.x + (128), position.y, 0), VGet(112, 52, 0), "agriculture_button", DIPLOID_LAYER_01);

	//工業ボタン関連
	industrial_button.SwitchButtonBOX_Init(VGet(position.x + (128), position.y + (52), 0), VGet(112, 52, 0), "industrial_button", DIPLOID_LAYER_01);

	//科学ボタン関連
	science_button.SwitchButtonBOX_Init(VGet(position.x + (128), position.y + (52 * 2), 0), VGet(112, 52, 0), "science_button", DIPLOID_LAYER_01);

}

void CommandUI::Push(DiploidEngineImpact& impact)
{
	//主要ボタンをプッシュ
	development_button.SwitchButtonBOX_Push(impact);
	research_button.SwitchButtonBOX_Push(impact);
	policy_button.SwitchButtonBOX_Push(impact);
	defense_button.SwitchButtonBOX_Push(impact);
	information_button.SwitchButtonBOX_Push(impact);
}

void CommandUI::Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//開発ボタンアップデート
	if (development_button_flag = development_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//農業ボタンの追加
		agriculture_button_systme.OnePushBOX_Impact(impact, agriculture_button.box);
		agriculture_button_systme.FlagReset_OneDeleteBOX();//削除フラグのリセット

		//農業ボタンのアップデート
		if (agriculture_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
		{

			//他のボタンをオフにする
			industrial_button.SwitchButton_Flag_Change(false);
			science_button.SwitchButton_Flag_Change(false);
		}


		//工業ボタンの追加
		industrial_button_systme.OnePushBOX_Impact(impact, industrial_button.box);
		industrial_button_systme.FlagReset_OneDeleteBOX();//削除フラグのリセット

		//工業ボタンのアップデート
		if (industrial_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
		{

			//他のボタンをオフにする
			agriculture_button.SwitchButton_Flag_Change(false);
			science_button.SwitchButton_Flag_Change(false);
		}


		//科学ボタンの追加
		science_button_system.OnePushBOX_Impact(impact, science_button.box);
		science_button_system.FlagReset_OneDeleteBOX();//削除フラグのリセット

		//科学ボタンのアップデート
		if (science_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
		{

			//他のボタンをオフにする
			agriculture_button.SwitchButton_Flag_Change(false);
			industrial_button.SwitchButton_Flag_Change(false);
		}


		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);
	}
	else
	{
		//農業ボタンの削除
		if (agriculture_button_systme.GetOnePushBOX_Flag() == true)
		{
			agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
			agriculture_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット
		}

		//工業ボタンの削除
		if (industrial_button_systme.GetOnePushBOX_Flag() == true)
		{
			industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
			industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット
		}

		//科学ボタンの削除
		if (science_button_system.GetOnePushBOX_Flag() == true)
		{
			science_button_system.OneDeleteBOX_Impact(impact, "science_button");
			science_button_system.FlagReset_OnePushBOX();//プッシュフラグのリセット
		}
	}


	//研究ボタンアップデート
	if (research_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//農業ボタンの削除
		agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
		agriculture_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット

		//工業ボタンの削除
		industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
		industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット

		//科学ボタンの削除
		industrial_button_systme.OneDeleteBOX_Impact(impact, "science_button");
		industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット


		//他のボタンをオフにする
		development_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);

		industrial_button.SwitchButton_Flag_Change(false);
		science_button.SwitchButton_Flag_Change(false);
		agriculture_button.SwitchButton_Flag_Change(false);
	}

	//政策ボタンアップデート
	if (policy_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//農業ボタンの削除
		agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
		agriculture_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット

		//工業ボタンの削除
		industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
		industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット

		//科学ボタンの削除
		industrial_button_systme.OneDeleteBOX_Impact(impact, "science_button");
		industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット


		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
		defense_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);

		industrial_button.SwitchButton_Flag_Change(false);
		science_button.SwitchButton_Flag_Change(false);
		agriculture_button.SwitchButton_Flag_Change(false);
	}

	//防衛ボタンアップデート
	if (defense_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//農業ボタンの削除
		agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
		agriculture_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット

		//工業ボタンの削除
		industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
		industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット

		//科学ボタンの削除
		industrial_button_systme.OneDeleteBOX_Impact(impact, "science_button");
		industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット


		//他のボタンをオフにする
		research_button.SwitchButton_Flag_Change(false);
		policy_button.SwitchButton_Flag_Change(false);
		development_button.SwitchButton_Flag_Change(false);
		information_button.SwitchButton_Flag_Change(false);

		industrial_button.SwitchButton_Flag_Change(false);
		science_button.SwitchButton_Flag_Change(false);
		agriculture_button.SwitchButton_Flag_Change(false);
	}

	//情報ボタンアップデート
	if (information_button.SwitchButtonBOX_Update(mouse_input_button_type, impact, input) == true)
	{
		//農業ボタンの削除
		agriculture_button_systme.OneDeleteBOX_Impact(impact, "agriculture_button");
		agriculture_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット

		//工業ボタンの削除
		industrial_button_systme.OneDeleteBOX_Impact(impact, "industrial_button");
		industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット

		//科学ボタンの削除
		industrial_button_systme.OneDeleteBOX_Impact(impact, "science_button");
		industrial_button_systme.FlagReset_OnePushBOX();//プッシュフラグのリセット


		//他のボタンをオフにする
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
		development_button.SwitchButtonBOX_Draw();//開発ボタンの描写
		research_button.SwitchButtonBOX_Draw();//研究ボタンの描写
		policy_button.SwitchButtonBOX_Draw();//政策ボタンの描写
		defense_button.SwitchButtonBOX_Draw();//防衛ボタンの描写
		information_button.SwitchButtonBOX_Draw();//情報ボタンの描写

		//開発ボタンがオンの時
		if (development_button_flag == true)
		{
			agriculture_button.SwitchButtonBOX_Draw();//農業ボタンの描写
			industrial_button.SwitchButtonBOX_Draw();//工業ボタンの描写
			science_button.SwitchButtonBOX_Draw();//科学ボタンの描写
		}
	}
}