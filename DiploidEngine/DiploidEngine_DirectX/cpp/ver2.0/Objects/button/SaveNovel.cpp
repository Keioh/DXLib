#include "ver2.0/Objects/button/SaveNovel.h"

void SaveNovel::Load()
{
	//アニメーション画像の読み込み
	anime.Load("texter/novel/button/save_novel/0.png");
	anime.Load("texter/novel/button/save_novel/1.png");
	anime.Load("texter/novel/button/save_novel/2.png");
	anime.Load("texter/novel/button/save_novel/3.png");
	anime.Load("texter/novel/button/save_novel/4.png");
}

void SaveNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//ボタンの初期化
	anime.Init(pos, 5);//アニメーションの初期化
	anime.SetAnimationSpeed(300);
}

void SaveNovel::Update(DiploidEngineInput& input, float frame_time)
{
	anime.Update();//アニメーションのアップデート
	button.Updata(&input);//ボタンのアップデート
}

void SaveNovel::Draw(float frame_time, bool draw, bool debug)
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


void SaveNovel::Reset()
{
	button.SetSelectedUI(-1);
}

void SaveNovel::SetSelected(int new_flag)
{
	button.SetSelectedUI(new_flag);
}


bool SaveNovel::GetHit()
{
	return button.GetHit();
}

bool SaveNovel::GetClick()
{
	return button.GetClick();
}

int SaveNovel::GetSelected()
{
	return button.GetSelectedUI();
}
