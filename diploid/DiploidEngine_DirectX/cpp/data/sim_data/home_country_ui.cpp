#include "data/sim_data/home_country_ui.h"


void CommandUI::Load()
{
	military_graphics.Load("texter/sim_texter/military.png");//軍事コマンドの画像の読み込み
	production_graphics.Load("texter/sim_texter/production.png");//生産コマンドの画像の読み込み
	construction_graphics.Load("texter/sim_texter/construction.png");//建設コマンドの画像の読み込み
	politics_graphics.Load("texter/sim_texter/politics.png");//政治コマンドの画像の読み込み

	military.Load(military_graphics.GetGraphicsHandl());//軍事コマンドの画像ハンドルを渡す。
	production.Load(production_graphics.GetGraphicsHandl());//生産コマンドの画像ハンドルを渡す。
	construction.Load(construction_graphics.GetGraphicsHandl());//建設コマンドの画像ハンドルを渡す。
	politics.Load(politics_graphics.GetGraphicsHandl());//政治コマンドの画像ハンドルを渡す。

}

void CommandUI::Init(VECTOR pos, float scale)
{
	//軍事コマンド
	military.Init(pos, VGet(512, 256, 0), scale);

	//建設コマンド
	construction.Init(VGet(pos.x, pos.y + (256 * scale), 0.0f), VGet(512, 256, 0), scale);

	//政治コマンド
	politics.Init(VGet(pos.x, pos.y + ((256 * 2) * scale), 0.0f), VGet(512, 256, 0), scale);


	//生産コマンド
	production.Init(VGet(pos.x + (512 * scale), pos.y, 0.0f), VGet(512, 256, 0), scale);

}

void CommandUI::Updata(DiploidEngineInput* input)
{
	if (collision_active_flag == true)//当たり判定フラグがオンだったら
	{
		//軍事コマンドの更新
		military.Updata(input);

		//建設コマンドの更新
		construction.Updata(input);

		//政治コマンドの更新
		politics.Updata(input);


		//軍事コマンドがクリックされたら
		if (military.GetClick() == true)
		{
			//政治コマンドをオフにする。
			politics.SetSelectedUI(-1);

			//建設コマンドをオフにする。
			construction.SetSelectedUI(-1);
		}

		//建設コマンドがクリックされたら
		if (construction.GetClick() == true)
		{
			//軍事コマンドをオフにする。
			military.SetSelectedUI(-1);

			//政治コマンドをオフにする。
			politics.SetSelectedUI(-1);
		}

		//政治コマンドがクリックされたら
		if (politics.GetClick() == true)
		{
			//軍事コマンドをオフにする。
			military.SetSelectedUI(-1);

			//建設コマンドをオフにする。
			construction.SetSelectedUI(-1);
		}


		//軍事コマンドが選択されてたら
		if (military.GetSelectedUI() == 1)
		{	
			//生産コマンドの更新
			production.Updata(input);
		}
		else
		{
			//生産コマンドをオフにする。
			production.SetSelectedUI(-1);
		}


		//建設コマンドが選択されていなかったら
		if (construction.GetSelectedUI() == -1)
		{

		}
	}
}

void CommandUI::Draw(bool draw, bool debug)
{
	if (draw == true)
	{	
		//軍事コマンドの描画
		military.Draw(draw, debug);

		//建設コマンドの描画
		construction.Draw(draw, debug);

		//政治コマンドの描画
		politics.Draw(draw, debug);


		//軍事コマンドが選択されていたら
		if (military.GetSelectedUI() == 1)
		{
			//生産コマンドの描画
			production.Draw(draw, debug);
		}
	}
}


bool CommandUI::GetHit()
{
	if ((military.GetHit() || production.GetHit() || construction.GetHit() || politics.GetHit()) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CommandUI::ResetFlag()
{
	military.SetSelectedUI(-1);
	construction.SetSelectedUI(-1);
	production.SetSelectedUI(-1);
	politics.SetSelectedUI(-1);
}

void CommandUI::SetCollisionActiveFlag(bool flag)
{
	collision_active_flag = flag;
}

bool CommandUI::GetCollisionActiveFlag()
{
	return collision_active_flag;
}