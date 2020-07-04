#include "data/res_data/UI/result_ui.h"

void ResultUI::Load()
{
	back_image.Load("texter/res/result/back.png");
	string_image.Load("texter/res/result/string.png");
	string_00_image.Load("texter/res/result/string_00.png");
	string_01_image.Load("texter/res/result/string_01.png");
	string_02_image.Load("texter/res/result/string_02.png");

	as_up_image.Load("texter/res/result/as_up.png");
	as_up_button.Load(as_up_image.GetGraphicsHandl());

	hp_up_image.Load("texter/res/result/hp_up.png");
	hp_up_button.Load(hp_up_image.GetGraphicsHandl());

	cp_up_image.Load("texter/res/result/cp_up.png");
	cp_up_button.Load(cp_up_image.GetGraphicsHandl());

}

void ResultUI::Init(VECTOR pos)
{
	back_image.Init(VGet(0, 0, 0), false);
	string_image.Init(VGet(1280/2 - (128 * 2.0f), 50,0), false);
	string_image.SetScale(2.0f, 2.0f);

	string_00_image.Init(VGet(1280 / 2 - (128 * 2.0f), 150, 0), false);
	string_00_image.SetScale(2.0f, 2.0f);

	string_01_image.Init(VGet(1280 / 2 - (128 * 2.0f), 150, 0), false);
	string_01_image.SetScale(2.0f, 2.0f);

	string_02_image.Init(VGet(1280 / 2 - (128 * 2.0f), 150, 0), false);
	string_02_image.SetScale(2.0f, 2.0f);

	as_up_button.Init(VGet(1280 / 2 - ((128 * 1.5f) / 2) - (128 * 1.5f) - 48, 720 / 2, 0), VGet(128, 64, 0), 1.5f);
	hp_up_button.Init(VGet(1280 / 2 - ((128 * 1.5f) / 2), 720 / 2, 0), VGet(128, 64, 0), 1.5f);
	cp_up_button.Init(VGet(1280 / 2 - ((128 * 1.5f) / 2) + (128 * 1.5f) + 48, 720 / 2, 0), VGet(128, 64, 0), 1.5f);

}

void ResultUI::Update()
{
	if (active_flag == true)
	{
		input.Update();

		as_up_button.Updata(&input);
		hp_up_button.Updata(&input);
		cp_up_button.Updata(&input);
	}
}

void ResultUI::Draw(bool draw)
{
	if (active_flag == true)
	{
		back_image.Draw(draw);
		as_up_button.Draw(draw);
		hp_up_button.Draw(draw);
		cp_up_button.Draw(draw);

		string_image.Draw(draw);

		if (as_up_button.GetHit() == true)
		{
			string_00_image.Draw(draw);
		}

		if (hp_up_button.GetHit() == true)
		{
			string_01_image.Draw(draw);
		}

		if (cp_up_button.GetHit() == true)
		{
			string_02_image.Draw(draw);
		}
	}
}


void ResultUI::SetActiveFlag(bool new_flag)
{
	active_flag = new_flag;
}

bool ResultUI::GetActiveFlag()
{
	return active_flag;
}