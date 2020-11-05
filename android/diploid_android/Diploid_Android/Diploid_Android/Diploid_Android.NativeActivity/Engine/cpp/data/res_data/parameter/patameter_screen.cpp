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


	ui_box.Init(VGet(0, android_screen.GetScreenSizeY() - 222, 0), VGet(android_screen.GetScreenSizeX(), android_screen.GetScreenSizeY(), 0), GetColor(20, 20, 20));
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


	//職業、生まれ、性別、年齢から基礎ステータスと使用可能ポイントを決める。
	parameter_update();


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

	//パラメータポイントなどの表示
	ui_draw(draw);

	//情報の表示
	info_ui_draw(draw);
}


void ParameterScreen::parameter_update()
{
	switch (birth_button.GetParameterValue())
	{
	case BIRTH_NONE://生まれが虚無なら
		character_data.parameter_points = 6;
		break;

	case BIRTH_REINCARNATION://生まれが転生者なら
		character_data.parameter_points = 48;
		break;

	case BIRTH_TRANSFER_LOCATION://生まれが転移者なら
		character_data.parameter_points = 6;
		break;

	case BIRTH_HUMAN://生まれが人族なら
		character_data.parameter_points = 12;
		break;

	case BIRTH_BEASTMAN://生まれが獣人族なら
		character_data.parameter_points = 12;
		break;

	case BIRTH_SPIRITS://生まれが精霊族なら
		character_data.parameter_points = 12;
		break;

	case BIRTH_CAVE_TRIBE://生まれが岩窟族なら
		character_data.parameter_points = 12;
		break;

	case BIRTH_DEMONIC://生まれが魔族なら
		character_data.parameter_points = 24;
		break;

	case BIRTH_ROYAL_FALMILY://生まれが王族なら
		character_data.parameter_points = 12;
		break;

	case BIRTH_FAMILY_OF_GODS://生まれが神族なら
		character_data.parameter_points = 36;
		break;

	case BIRTH_IMMORTAL://生まれが不死者なら
		character_data.parameter_points = 48;
		break;

	default:
		break;
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
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "人族", GetColor(255, 255, 255));
		break;

	case 4:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "獣人族", GetColor(255, 255, 255));
		break;

	case 5:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "精霊族", GetColor(255, 255, 255));
		break;

	case 6:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "岩窟族", GetColor(255, 255, 255));
		break;

	case 7:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "魔族", GetColor(255, 255, 255));
		break;

	case 8:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "王族", GetColor(255, 255, 255));
		break;

	case 9:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "神族", GetColor(255, 255, 255));
		break;

	case 10:
		DrawString(player_info_pos.x + 160, player_info_pos.y + 8 + (128 + 64 + 20), "不死者", GetColor(255, 255, 255));
		break;

	default:
		break;
	}

}


void ParameterScreen::ui_draw(bool draw)
{
	ui_box.Draw(draw);

	if (draw == true)
	{
		DrawFormatString(30, android_screen.GetScreenSizeY() - 215, GetColor(200, 200, 200), "使用可能ポイント：%d", character_data.parameter_points);
		DrawFormatString(30, android_screen.GetScreenSizeY() - (215 - 60), GetColor(200, 200, 200),"基礎ステータス合計値：%d", character_data.GetParameterAllPoints());
		//DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "", GetColor(200, 200, 200));
	}
}

void ParameterScreen::info_ui_draw(bool draw)
{
	if (draw == true)
	{
		//STR
		if (str_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[STR]は筋力を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "攻撃力や最大装備重量に影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//DEX
		if (dex_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[DEX]は器用さを表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "攻撃力や鍵開けなどに影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//CON
		if (con_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[CON]は体幹を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "体力や最大装備重量に影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//INT
		if (int_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[INT]は知識を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "魔法攻撃力や鑑定に影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//LUK
		if (luk_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[LUK]は幸運を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "回避や発見に影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//AGI
		if (agi_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[AGI]は素早さを表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "回避や移動力に影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//RES
		if (res_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[RES]は属性防御を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "属性攻撃に対して軽減する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//ATK
		if (atk_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[ATK]は攻撃力を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "攻撃力に影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//CRI
		if (cri_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[CRI]は致命率を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "致命発生率に影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//DEF
		if (def_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[DEF]は物理防御を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "物理攻撃に対して軽減する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//SAN
		if (san_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[SAN]は正気を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "自分の理性に影響する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}

		//WILL
		if (will_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[意志]は意志を表す。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "正気に対する影響を軽減する。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "ステータス補正タイプ：固定値", GetColor(200, 200, 200));
		}


		//職業
		if (profession_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[職業]は初期に持つ特技を決める。", GetColor(200, 200, 200));
		}

		//生まれ
		if (birth_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawFormatString(30, android_screen.GetScreenSizeY() - 215, GetColor(200, 200, 200), "[生まれ]は使用可能ポイントを決める。: %d", character_data.parameter_points);

			//フレーバー文
			switch (birth_button.GetParameterValue())
			{
			case BIRTH_NONE://生まれが虚無なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "自分が誰から生まれたのかすら分からない。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "本当に虚無から生まれたのかもしれない。", GetColor(150, 55, 55));
				break;

			case BIRTH_REINCARNATION://生まれが転生者なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "別世界、別次元の魂を持つ。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "この世界で生まれ育つ。", GetColor(150, 55, 55));
				break;

			case BIRTH_TRANSFER_LOCATION://生まれが転移者なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "別世界、別次元の魂と肉体を持つ。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "別世界で生れ、この世界で生きる。", GetColor(150, 55, 55));
				break;

			case BIRTH_HUMAN://生まれが人族なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "この世界の3割を占める種族。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "他種族より全体の基礎能力が劣る。", GetColor(150, 55, 55));
				break;

			case BIRTH_BEASTMAN://生まれが獣人族なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "この世界の3割を占める種族。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "他種族より器用で俊敏な傾向にある。", GetColor(150, 55, 55));
				break;

			case BIRTH_SPIRITS://生まれが精霊族なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "この世界の2割を占める種族。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "他種族より知性と意志に恵まれる。", GetColor(150, 55, 55));
				break;

			case BIRTH_CAVE_TRIBE://生まれが岩窟族なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "この世界の1割を占める種族。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "他種族より体力が高い。", GetColor(150, 55, 55));
				break;

			case BIRTH_DEMONIC://生まれが魔族なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "この世界の1割を占める種族。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "他種族より全体の基礎能力が高い。", GetColor(150, 55, 55));
				break;

			case BIRTH_ROYAL_FALMILY://生まれが王族なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "太古より一国を治めてきた一族。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "王としての誇りを持つ。", GetColor(150, 55, 55));
				break;

			case BIRTH_FAMILY_OF_GODS://生まれが神族なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "世界を創造した神々の子孫。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "今は神話として知られる存在。", GetColor(150, 55, 55));
				break;

			case BIRTH_IMMORTAL://生まれが不死者なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "何時代を生きているのか。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "死を求めているのかもしれない。", GetColor(150, 55, 55));
				break;

			default:
				break;
			}
		}

		//性別
		if (sex_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[性別]は一人称に影響する。", GetColor(200, 200, 200));

			//フレーバー文
			switch (sex_button.GetParameterValue())
			{
			case SEX_NONE://性別が無性なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "生れながら無性だった。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：我, 己, 自分", GetColor(150, 55, 55));
				break;

			case SEX_MALE://性別が男性なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "男の象徴が存在する。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：俺, 僕, 自分, 儂", GetColor(150, 55, 55));
				break;

			case SEX_FEMALE://性別が女性なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "生命を生み出す存在。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：私, わらわ, 僕", GetColor(150, 55, 55));
				break;

			case SEX_FORMER_AMPHOTERIC://性別が両性なら
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "生命の神秘を感じる。", GetColor(150, 55, 55));
				DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：自分, 私, 僕", GetColor(150, 55, 55));
				break;

			default:
				break;
			}
		}

		//年齢
		if (age_button.GetInfoButtonPtr()->GetSelectedUI() == true)
		{
			ui_box.Draw(draw);
			DrawString(30, android_screen.GetScreenSizeY() - 215, "[年齢]は一部のパラメータに影響を及ぼす。", GetColor(200, 200, 200));
			DrawString(30, android_screen.GetScreenSizeY() - (215 - 60), "年齢によって一人称が変わる。", GetColor(200, 200, 200));

			//性別と年齢による一人称
			switch (sex_button.GetParameterValue())
			{
			case SEX_NONE://性別が無性なら
				if ((age_button.GetParameterValue() >= 0) && (age_button.GetParameterValue() < 30))//０歳以上３０歳未満
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：自分", GetColor(200, 200, 200));
				}

				if ((age_button.GetParameterValue() >= 30) && (age_button.GetParameterValue() < 50))//３０歳以上５０歳未満
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：我", GetColor(200, 200, 200));
				}

				if (age_button.GetParameterValue() >= 50)//５０歳以上
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：己", GetColor(200, 200, 200));
				}
				break;

			case SEX_MALE://性別が男性なら
				if ((age_button.GetParameterValue() >= 0) && (age_button.GetParameterValue() < 15))//０歳以上15歳未満
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：僕", GetColor(200, 200, 200));
				}

				if ((age_button.GetParameterValue() >= 15) && (age_button.GetParameterValue() < 50))//15歳以上5０歳未満
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：俺", GetColor(200, 200, 200));
				}

				if (age_button.GetParameterValue() >= 50)//50歳以上
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：儂", GetColor(200, 200, 200));
				}
				break;

			case SEX_FEMALE://性別が女性なら
				if ((age_button.GetParameterValue() >= 0) && (age_button.GetParameterValue() < 15))//０歳以上15歳未満
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：僕", GetColor(200, 200, 200));
				}

				if ((age_button.GetParameterValue() >= 15) && (age_button.GetParameterValue() < 50))//15歳以上5０歳未満
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：私", GetColor(200, 200, 200));
				}

				if (age_button.GetParameterValue() >= 50)//50歳以上
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：わらわ", GetColor(200, 200, 200));
				}
				break;

			case SEX_FORMER_AMPHOTERIC://性別が両性なら
				if ((age_button.GetParameterValue() >= 0) && (age_button.GetParameterValue() < 15))//０歳以上15歳未満
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：僕", GetColor(200, 200, 200));
				}

				if ((age_button.GetParameterValue() >= 15) && (age_button.GetParameterValue() < 50))//15歳以上5０歳未満
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：私", GetColor(200, 200, 200));
				}

				if (age_button.GetParameterValue() >= 50)//50歳以上
				{
					DrawString(30, android_screen.GetScreenSizeY() - (215 - 60 * 2), "一人称：自分", GetColor(200, 200, 200));
				}
				break;

			default:
				break;
			}
		}
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