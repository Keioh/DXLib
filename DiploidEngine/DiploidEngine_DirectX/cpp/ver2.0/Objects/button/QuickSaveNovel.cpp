#include "ver2.0/Objects/button/QuickSaveNovel.h"

void QuickSaveNovel::Load()
{
	//アニメーション画像の読み込み
	anime.Load("texter/novel/button/q_save_novel/0.png");
	anime.Load("texter/novel/button/q_save_novel/1.png");
	anime.Load("texter/novel/button/q_save_novel/2.png");
	anime.Load("texter/novel/button/q_save_novel/3.png");
	anime.Load("texter/novel/button/q_save_novel/4.png");
}

void QuickSaveNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//ボタンの初期化
	anime.Init(pos, 5);//アニメーションの初期化
	anime.SetAnimationSpeed(300);
}

void QuickSaveNovel::Update(DiploidEngineInput& input, float frame_time)
{
	anime.Update();//アニメーションのアップデート
	button.Updata(&input);//ボタンのアップデート
}

void QuickSaveNovel::Draw(float frame_time, bool draw, bool debug)
{
	if (draw == true)
	{	
		if (button.GetSelectedUI() == 1)//選択状態のとき
		{
			SetDrawBright(255, 255, 255);
			anime.Draw(frame_time);//アニメーションの描画
			//anime.StackDraw();
		}
		else//選択状態じゃないとき
		{
			if (button.GetHit() == true)//カーソルがボタンに当たっている
			{
				SetDrawBright(255  * 0.9, 255 *  0.9, 255 * 0.9);
				anime.Draw(frame_time);//アニメーションの描画
				//anime.StackDraw();//アニメーションの描画(スタック描画)
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


void QuickSaveNovel::Reset()
{
	button.SetSelectedUI(-1);
}

void QuickSaveNovel::SetSelected(int new_flag)
{
	button.SetSelectedUI(new_flag);
}


bool QuickSaveNovel::GetHit()
{
	return button.GetHit();
}

bool QuickSaveNovel::GetClick()
{
	return button.GetClick();
}

int QuickSaveNovel::GetSelected()
{
	return button.GetSelectedUI();
}
