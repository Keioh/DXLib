#include "data/res_data/parameter/patameter_screen.h"

void ParameterScreen::Load()
{
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

}

void ParameterScreen::Init()
{
	str_button.Init(VGet(0, 500, 0), VGet(256, 128, 0), "STR");
	dex_button.Init(VGet(0, 500 + 128, 0), VGet(256, 128, 0), "DEX");
	con_button.Init(VGet(0, 500 + (128 * 2), 0), VGet(256, 128, 0), "CON");
	int_button.Init(VGet(0, 500 + (128 * 3), 0), VGet(256, 128, 0), "INT");
	luk_button.Init(VGet(0, 500 + (128 * 4), 0), VGet(256, 128, 0), "LUK");
	agi_button.Init(VGet(0, 500 + (128 * 5), 0), VGet(256, 128, 0), "AGI");

	res_button.Init(VGet(512 + 40, 500, 0), VGet(256, 128, 0), "RES");
	atk_button.Init(VGet(512 + 40, 500 + 128, 0), VGet(256, 128, 0), "ATK");
	cri_button.Init(VGet(512 + 40, 500 + (128 * 2), 0), VGet(256, 128, 0), "CRI");
	def_button.Init(VGet(512 + 40, 500 + (128 * 3), 0), VGet(256, 128, 0), "DEF");
	san_button.Init(VGet(512 + 40, 500 + (128 * 4), 0), VGet(256, 128, 0), "SAN");
	will_button.Init(VGet(512 + 40, 500 + (128 * 5), 0), VGet(256, 128, 0), "WILL");

}

void ParameterScreen::Update(DiploidEngineInput* input)
{
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

}

void ParameterScreen::Draw(bool draw, bool debug)
{
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

}