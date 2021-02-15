#include "ver2.0/Objects/button/OptionNovel.h"

void OptionNovel::Load()
{
	//アニメーション画像の読み込み
	anime.Load("texter/novel/button/option/0.png");
	anime.Load("texter/novel/button/option/1.png");
	anime.Load("texter/novel/button/option/2.png");
	anime.Load("texter/novel/button/option/3.png");
	anime.Load("texter/novel/button/option/4.png");
}

void OptionNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//ボタンの初期化
	anime.Init(pos, 5);//アニメーションの初期化
	anime.SetAnimationSpeed(5);
}

void OptionNovel::Update(DiploidEngineInput& input)
{
	anime.Update();//アニメーションのアップデート
	button.Updata(&input);//ボタンのアップデート
}

void OptionNovel::Draw(bool draw, bool debug)
{
	if (draw == true)
	{	
		if (button.GetSelectedUI() == 1)//選択状態のとき
		{
			SetDrawBright(255, 255, 255);
			anime.Draw();//アニメーションの描画(スタック描画)
			//anime.StackDraw();//アニメーションの描画
		}
		else//選択状態じゃないとき
		{
			if (button.GetHit() == true)//カーソルがボタンに当たっている
			{
				SetDrawBright(255  * 0.9, 255 *  0.9, 255 * 0.9);
				//anime.StackDraw();//アニメーションの描画(スタック描画)
				anime.Draw();//アニメーションの描画
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


void OptionNovel::Reset()
{
	button.SetSelectedUI(-1);
}


void OptionNovel::SetSelected(int new_flag)
{
	button.SetSelectedUI(new_flag);
}


bool OptionNovel::GetHit()
{
	return button.GetHit();
}

bool OptionNovel::GetClick()
{
	return button.GetClick();
}

int OptionNovel::GetSelected()
{
	return button.GetSelectedUI();
}