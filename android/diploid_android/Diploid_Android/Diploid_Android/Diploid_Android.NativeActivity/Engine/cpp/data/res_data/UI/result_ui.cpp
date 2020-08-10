#include "data/res_data/UI/result_ui.h"

void ResultUI::Load()
{
	back_image.Load("res/result/back.png");
	string_image.Load("res/result/string.png");
	string_00_image.Load("res/result/string_00.png");
	string_01_image.Load("res/result/string_01.png");
	string_02_image.Load("res/result/string_02.png");

	as_up_image.Load("res/result/as_up.png");
	as_up_button.Load(as_up_image.GetGraphicsHandl());

	hp_up_image.Load("res/result/hp_up.png");
	hp_up_button.Load(hp_up_image.GetGraphicsHandl());

	cp_up_image.Load("res/result/cp_up.png");
	cp_up_button.Load(cp_up_image.GetGraphicsHandl());

	confirm_image.Load("res/result/confirm.png");
	confirm_button.Load(confirm_image.GetGraphicsHandl());

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

	confirm_button.Init(VGet(1280 / 2 - ((128 * 1.0f) / 2), 720 - (64 + 24), 0), VGet(128, 64, 0), 1.0f);
}

void ResultUI::Update(Player* player, DayUI* day_ui)
{
	if (active_flag == true)
	{
		input.Update();

		as_up_button.Updata(&input);
		hp_up_button.Updata(&input);
		cp_up_button.Updata(&input);


		//ASアップボタンを押したら
		if ((as_up_button.GetClick() == true) && (as_up_button.GetHit() == true))
		{
			any_button_active_flags = AS_UP_SELECTED;

			//他のボタンをオフにする
			hp_up_button.SetSelectedUI(-1);
			cp_up_button.SetSelectedUI(-1);
		}

		//HPアップボタンを押したら
		if ((hp_up_button.GetClick() == true) && (hp_up_button.GetHit() == true))
		{
			any_button_active_flags = HP_UP_SELECTED;

			//他のボタンをオフにする
			as_up_button.SetSelectedUI(-1);
			cp_up_button.SetSelectedUI(-1);
		}

		//CPアップボタンを押したら
		if ((cp_up_button.GetClick() == true) && (cp_up_button.GetHit() == true))
		{
			any_button_active_flags = CP_UP_SELECTED;

			//他のボタンをオフにする
			as_up_button.SetSelectedUI(-1);
			hp_up_button.SetSelectedUI(-1);
		}

		//どの強化ボタンも押されていなかったら
		if ((as_up_button.GetSelectedUI() == -1) && (hp_up_button.GetSelectedUI() == -1) && (cp_up_button.GetSelectedUI() == -1))
		{
			any_button_active_flags = NO_SELECTED;
		}


		//○○アップボタンが有効になっていたら
		if (any_button_active_flags != 0)
		{
			//決定ボタンの処理を始める
			confirm_button.Updata(&input);

			if (confirm_button.GetSelectedUI() == 1)
			{
				//playerのASを1上げる
				if (any_button_active_flags == AS_UP_SELECTED)
				{
					player->AddAttackSpeed(1);
				}

				//playerのHP回復確率を1上げる
				if (any_button_active_flags == HP_UP_SELECTED)
				{
					player->AddHpRecoveryProbability(1);
				}

				//playerのCP回復確率を1上げる
				if (any_button_active_flags == CP_UP_SELECTED)
				{
					player->AddCpRecoveryProbability(1);
				}
				
				day_ui->AddDay(1);//日付を進める
				day_ui->SetAcitiveFlag(true);//DayUIを有効にする。

				//状態を保存
				state = any_button_active_flags;

				//ボタンを初期化
				as_up_button.SetSelectedUI(-1);
				hp_up_button.SetSelectedUI(-1);
				cp_up_button.SetSelectedUI(-1);

				confirm_button.SetSelectedUI(-1);

				//UIを非アクティブに
				active_flag = false;
			}
		}
	}
}

void ResultUI::Draw(bool draw)
{
	if (active_flag == true)
	{
		back_image.Draw(draw);
		as_up_button.Draw(draw, true);
		hp_up_button.Draw(draw, true);
		cp_up_button.Draw(draw, true);

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

		if (any_button_active_flags != 0)
		{
			confirm_button.Draw(draw, true);
		}
	}
}


void ResultUI::SetActiveFlag(bool new_flag)
{
	active_flag = new_flag;
}


int ResultUI::GetState()
{
	return state;
}

bool ResultUI::GetActiveFlag()
{
	return active_flag;
}