#include "data/res_data/parameter/patameter_screen.h"

void ParameterScreen::Load()
{
	//パラメータ関連
	str_button.Load();
	dex_button.Load();
	con_button.Load();
	int_button.Load();
	luk_button.Load();
	agi_button.Load();	
	res_button.Load();
	atk_button.Load();
	cri_button.Load();
	def_button.Load();
	san_button.Load();
	will_button.Load();

	//職業
	profession_button.Load();

	//生まれ
	birth_button.Load();

	//性別
	sex_button.Load();

	//年齢
	age_button.Load();

}

void ParameterScreen::Init()
{
	profession_button.Init(VGet(player_info_pos.x, player_info_pos.y, 0), VGet(192, 128, 0), "職業", false);	
	profession_button.SetMaxValue(PROFESSION_VALUE);
	profession_button.SetMiniValue(-1);

	birth_button.Init(VGet(player_info_pos.x, player_info_pos.y + (128 + 64 + 20), 0), VGet(192, 128, 0), "出生", false);
	birth_button.SetMaxValue(BIRTH_VALUE);
	birth_button.SetMiniValue(-1);

	sex_button.Init(VGet(player_info_pos.x + (512 + 40), player_info_pos.y + (128 + 64 + 20), 0), VGet(192, 128, 0), "性別", false);
	sex_button.SetMaxValue(SEX_VALUE);
	sex_button.SetMiniValue(-1);

	age_button.Init(VGet(player_info_pos.x + (512 + 40), player_info_pos.y, 0), VGet(192, 128, 0), "年齢");
	age_button.SetMaxValue(9999);
	age_button.SetMiniValue(0);


	str_button.Init(VGet(0, parameter_pos.y, 0), VGet(192, 128, 0), "STR");
	dex_button.Init(VGet(0, parameter_pos.y + (128 + 64 + 20), 0), VGet(192, 128, 0), "DEX");
	con_button.Init(VGet(0, parameter_pos.y + ((128 + 64 + 20) * 2), 0), VGet(192, 128, 0), "CON");
	int_button.Init(VGet(0, parameter_pos.y + ((128 + 64 + 20) * 3), 0), VGet(192, 128, 0), "INT");
	luk_button.Init(VGet(0, parameter_pos.y + ((128 + 64 + 20) * 4), 0), VGet(192, 128, 0), "LUK");
	agi_button.Init(VGet(0, parameter_pos.y + ((128 + 64 + 20) * 5), 0), VGet(192, 128, 0), "AGI");
	res_button.Init(VGet(512 + 40, parameter_pos.y, 0), VGet(192, 128, 0), "RES");
	atk_button.Init(VGet(512 + 40, parameter_pos.y + (128 + 64 + 20), 0), VGet(192, 128, 0), "ATK");
	cri_button.Init(VGet(512 + 40, parameter_pos.y + ((128 + 64 + 20) * 2), 0), VGet(192, 128, 0), "CRI");
	def_button.Init(VGet(512 + 40, parameter_pos.y + ((128 + 64 + 20) * 3), 0), VGet(192, 128, 0), "DEF");
	san_button.Init(VGet(512 + 40, parameter_pos.y + ((128 + 64 + 20) * 4), 0), VGet(192, 128, 0), "SAN");
	will_button.Init(VGet(512 + 40, parameter_pos.y + ((128 + 64 + 20) * 5), 0), VGet(192, 128, 0), "WIL");


	ui_box.Init(VGet(0, android_screen.GetScreenSizeY() - 300, 0), VGet(android_screen.GetScreenSizeX(), android_screen.GetScreenSizeY(), 0), GetColor(20, 20, 20));
	ui_box.SetFill(true);

}

void ParameterScreen::Update(DiploidEngineInput* input)
{
	//職業ボタン判定処理
	profession_button.Update(input);

	//生まれボタン判定処理
	birth_button.Update(input);

	//性別ボタン判定処理
	sex_button.Update(input);

	//年齢ボタン判定処理
	age_button.Update(input);


	//パラメータ関連のボタン判定処理
	str_button.Update(input);
	dex_button.Update(input);
	con_button.Update(input);
	int_button.Update(input);
	luk_button.Update(input);
	agi_button.Update(input);
	res_button.Update(input);
	atk_button.Update(input);
	cri_button.Update(input);
	def_button.Update(input);
	san_button.Update(input);
	will_button.Update(input);

	//職業ボタンの数値処理
	profession_update();

	//生まれボタンの数値処理
	birth_update();

	//性別ボタンの数値処理
	sex_update();


	//ボタンオフ処理	
	age_button_update();
	sex_button_update();
	birth_button_update();
	profession_button_update();
	str_button_update();//ここから下はパラメータ関連
	dex_button_update();
	con_button_update();
	int_button_update();
	luk_button_update();
	agi_button_update();
	res_button_update();
	atk_button_update();
	cri_button_update();
	def_button_update();
	san_button_update();
	will_button_update();

	//値の代入
	character_data.parameter_str = str_button.GetParameterValue();//STR
	character_data.parameter_dex = dex_button.GetParameterValue();//DEX
	character_data.parameter_con = con_button.GetParameterValue();//CON
	character_data.parameter_int = int_button.GetParameterValue();//INT
	character_data.parameter_luk = luk_button.GetParameterValue();//LUK
	character_data.parameter_agi = agi_button.GetParameterValue();//AGI
	character_data.parameter_res = res_button.GetParameterValue();//RES
	character_data.parameter_atk = atk_button.GetParameterValue();//ATK
	character_data.parameter_cri = cri_button.GetParameterValue();//CRI
	character_data.parameter_def = def_button.GetParameterValue();//DEF
	character_data.parameter_san = san_button.GetParameterValue();//SAN
	character_data.parameter_will = will_button.GetParameterValue();//WILL

}

void ParameterScreen::Draw(bool draw, bool debug)
{
	//職業ボタンの描画
	profession_button_draw(draw, debug);

	//生まれボタンの描画
	birth_button_draw(draw, debug);

	//性別ボタンの描画
	sex_button_draw(draw, debug);

	//年齢ボタンの描画
	age_button.Draw(draw, debug);

	//パラメータボタンの描画
	str_button.Draw(draw, debug);
	dex_button.Draw(draw, debug);
	con_button.Draw(draw, debug);
	int_button.Draw(draw, debug);
	luk_button.Draw(draw, debug);
	agi_button.Draw(draw, debug);
	res_button.Draw(draw, debug);
	atk_button.Draw(draw, debug);
	cri_button.Draw(draw, debug);
	def_button.Draw(draw, debug);
	san_button.Draw(draw, debug);
	will_button.Draw(draw, debug);

	if (str_button.GetInfoButtonPtr()->GetSelectedUI() == true)
	{
		ui_box.Draw(draw);
		DrawString(30, android_screen.GetScreenSizeY() - 240, "STRは筋力を表し、攻撃力に影響する。", GetColor(200, 200, 200));
	}
}

void ParameterScreen::age_button_update()
{
	//年齢の情報ボタンを押したら他の情報ボタンをオフにする。
	if ((age_button.GetInfoButtonPtr()->GetClick() == true) && (age_button.GetInfoButtonPtr()->GetHit() == true))
	{
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}

}

void ParameterScreen::sex_button_update()
{	
	//性別の情報ボタンを押したら他の情報ボタンをオフにする。
	if ((sex_button.GetInfoButtonPtr()->GetClick() == true) && (sex_button.GetInfoButtonPtr()->GetHit() == true))
	{
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::birth_button_update()
{
	//職業の情報ボタンを押したら他の情報ボタンをオフにする。
	if ((birth_button.GetInfoButtonPtr()->GetClick() == true) && (birth_button.GetInfoButtonPtr()->GetHit() == true))
	{
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::profession_button_update()
{
	//職業の情報ボタンを押したら他の情報ボタンをオフにする。
	if ((profession_button.GetInfoButtonPtr()->GetClick() == true) && (profession_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::str_button_update()
{
	//STRの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((str_button.GetInfoButtonPtr()->GetClick() == true) && (str_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::dex_button_update()
{
	//DEXの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((dex_button.GetInfoButtonPtr()->GetClick() == true) && (dex_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::con_button_update()
{
	//CONの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((con_button.GetInfoButtonPtr()->GetClick() == true) && (con_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::int_button_update()
{
	//INTの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((int_button.GetInfoButtonPtr()->GetClick() == true) && (int_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::luk_button_update()
{
	//LUKの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((luk_button.GetInfoButtonPtr()->GetClick() == true) && (luk_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::agi_button_update()
{
	//AGIの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((agi_button.GetInfoButtonPtr()->GetClick() == true) && (agi_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::res_button_update()
{
	//RESの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((res_button.GetInfoButtonPtr()->GetClick() == true) && (res_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::atk_button_update()
{
	//ATKの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((atk_button.GetInfoButtonPtr()->GetClick() == true) && (atk_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::cri_button_update()
{
	//CRIの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((cri_button.GetInfoButtonPtr()->GetClick() == true) && (cri_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::def_button_update()
{
	//DEFの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((def_button.GetInfoButtonPtr()->GetClick() == true) && (def_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::san_button_update()
{
	//SANの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((san_button.GetInfoButtonPtr()->GetClick() == true) && (san_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);

		will_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}

void ParameterScreen::will_button_update()
{
	//WILLの情報ボタンを押したら他の情報ボタンをオフにする。
	if ((will_button.GetInfoButtonPtr()->GetClick() == true) && (will_button.GetInfoButtonPtr()->GetHit() == true))
	{
		birth_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		profession_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		sex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		age_button.GetInfoButtonPtr()->SetSelectedUI(-1);


		str_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		dex_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		con_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		int_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		luk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		agi_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		res_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		atk_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		cri_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		def_button.GetInfoButtonPtr()->SetSelectedUI(-1);
		san_button.GetInfoButtonPtr()->SetSelectedUI(-1);
	}
}



void ParameterScreen::sex_update()
{
	if (sex_button.GetParameterValue() >= sex_button.GetParameterMaxValue())
	{
		sex_button.SetParameterValue(0);
	}

	if (sex_button.GetParameterValue() <= sex_button.GetParameterMiniValue())
	{
		sex_button.SetParameterValue(SEX_VALUE - 1);
	}
}

void ParameterScreen::sex_button_draw(bool draw, bool debug)
{
	sex_button.Draw(draw, debug);

	switch (sex_button.GetParameterValue())
	{
	case 0:
		DrawString(player_info_pos.x + (512 + 40) + 160, player_info_pos.y + (128 + 64 + 20) + 8, "無性", GetColor(255, 255, 255));
		break;

	case 1:
		DrawString(player_info_pos.x + (512 + 40) + 160, player_info_pos.y + (128 + 64 + 20) + 8, "男", GetColor(255, 255, 255));
		break;

	case 2:
		DrawString(player_info_pos.x + (512 + 40) + 160, player_info_pos.y + (128 + 64 + 20) + 8, "女", GetColor(255, 255, 255));
		break;

	case 3:
		DrawString(player_info_pos.x + (512 + 40) + 160, player_info_pos.y + (128 + 64 + 20) + 8, "元男", GetColor(255, 255, 255));
		break;

	case 4:
		DrawString(player_info_pos.x + (512 + 40) + 160, player_info_pos.y + (128 + 64 + 20) + 8, "元女", GetColor(255, 255, 255));
		break;

	case 5:
		DrawString(player_info_pos.x + (512 + 40) + 160, player_info_pos.y + (128 + 64 + 20) + 8, "両性", GetColor(255, 255, 255));
		break;

	default:
		break;
	}
}


void ParameterScreen::profession_update()
{
	if (profession_button.GetParameterValue() >= profession_button.GetParameterMaxValue())
	{
		profession_button.SetParameterValue(0);
	}

	if (profession_button.GetParameterValue() <= profession_button.GetParameterMiniValue())
	{
		profession_button.SetParameterValue(PROFESSION_VALUE - 1);
	}
}

void ParameterScreen::profession_button_draw(bool draw, bool debug)
{
	profession_button.Draw(draw, debug);

	switch (profession_button.GetParameterValue())
	{
	case 0:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8,"虚無", GetColor(255, 255, 255));
		break;

	case 1:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8, "剣聖", GetColor(255, 255, 255));
		break;

	case 2:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8, "魔者", GetColor(255, 255, 255));
		break;

	case 3:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8, "賢者", GetColor(255, 255, 255));
		break;

	case 4:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8, "守護者", GetColor(255, 255, 255));
		break;

	default:
		break;
	}
}


void ParameterScreen::birth_update()
{
	if (birth_button.GetParameterValue() >= birth_button.GetParameterMaxValue())
	{
		birth_button.SetParameterValue(0);
	}

	if (birth_button.GetParameterValue() <= birth_button.GetParameterMiniValue())
	{
		birth_button.SetParameterValue(BIRTH_VALUE - 1);
	}
}

void ParameterScreen::birth_button_draw(bool draw, bool debug)
{
	birth_button.Draw(draw, debug);

	switch (birth_button.GetParameterValue())
	{
	case 0:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "虚無", GetColor(255, 255, 255));
		break;

	case 1:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "転生者", GetColor(255, 255, 255));
		break;

	case 2:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "転移者", GetColor(255, 255, 255));
		break;

	case 3:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "商人", GetColor(255, 255, 255));
		break;

	case 4:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "武人", GetColor(255, 255, 255));
		break;

	case 5:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "貧民", GetColor(255, 255, 255));
		break;

	case 6:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "王族", GetColor(255, 255, 255));
		break;

	case 7:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "奴隷", GetColor(255, 255, 255));
		break;

	case 8:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "貴族", GetColor(255, 255, 255));
		break;

	case 9:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "平民", GetColor(255, 255, 255));
		break;

	case 10:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "不死者", GetColor(255, 255, 255));
		break;

	default:
		break;
	}

}



int ParameterScreen::GetProfessionValue()
{
	return profession_button.GetParameterValue();
}

int ParameterScreen::GetBirthValue()
{
	return birth_button.GetParameterValue();
}

CharacterData ParameterScreen::GetCharacterData()
{
	return character_data;
}

CharacterData* ParameterScreen::GetCharacterDataPtr()
{
	return& character_data;
}