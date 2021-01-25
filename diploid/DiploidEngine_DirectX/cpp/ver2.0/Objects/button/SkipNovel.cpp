#include "ver2.0/Objects/button/SkipNovel.h"

void SkipNovel::Load()
{
	//アニメーション画像の読み込み
	anime.Load("texter/novel/button/skip/0.png");
	anime.Load("texter/novel/button/skip/1.png");
	anime.Load("texter/novel/button/skip/2.png");
	anime.Load("texter/novel/button/skip/3.png");
}

void SkipNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//ボタンの初期化
	anime.Init(pos);//アニメーションの初期化

	box.Init(VGet(pos.x, pos.y - 10, pos.z), VGet(0, 8, 0), GetColor(250, 250, 250));
	box.SetFill(true);
}

void SkipNovel::Update(DiploidEngineInput& input)
{
	anime.Update();//アニメーションのアップデート
	button.Updata(&input);//ボタンのアップデート

	if (button.GetSelectedUI() == 1)//選択状態のとき
	{
		if (time > next_time)
		{
			next_flag = 1;//次へ行くflagを立てる
			time = 0;
		}
		else
		{
			time += skip_speed;
			next_flag = 0;
		}
	}
	else//選択状態でないとき
	{
		time = 0;

		//初期化
		next_flag = -1;
	}	
}

void SkipNovel::Draw(bool draw, bool debug)
{
	if (draw == true)
	{	
		box.Draw();

		if ((button.GetSelectedUI() == 1) && (next_flag >= 0))//選択状態のとき、かつnext_flagが０以上のとき
		{
			SetDrawBright(255, 255, 255);
			anime.StackDraw();//アニメーションの描画(スタック描画)
		}
		else//選択状態じゃないとき
		{
			if (button.GetHit() == true)//カーソルがボタンに当たっている
			{
				SetDrawBright(255  * 0.9, 255 *  0.9, 255 * 0.9);
				anime.StackDraw();//アニメーションの描画(スタック描画)
				SetDrawBright(255, 255, 255);
			}
			else//当たっていない
			{
				SetDrawBright(255  * 0.8, 255 * 0.8, 255 * 0.8);
				anime.Reset();//コマを最初から再生(初期化)
				anime.OneCellDraw();//最初の0コマ目を描画
				SetDrawBright(255, 255, 255);
			}
		}
	}

	if (debug == true)
	{
		button.Draw();//ボタンの描画
	}
}


void SkipNovel::SetSelected(int new_flag)
{
	if (new_flag == 1)
	{
		next_flag = 0;
	}

	if (new_flag == -1)
	{
		next_flag = -1;
	}

	button.SetSelectedUI(new_flag);
}


bool SkipNovel::GetHit()
{
	return button.GetHit();
}

bool SkipNovel::GetClick()
{
	return button.GetClick();
}

int SkipNovel::GetSelected()
{
	return button.GetSelectedUI();
}


int SkipNovel::GetNextFlag()
{
	return next_flag;
}