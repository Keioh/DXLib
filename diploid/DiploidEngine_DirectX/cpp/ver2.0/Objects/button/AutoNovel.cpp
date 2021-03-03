#include "ver2.0/Objects/button/AutoNovel.h"

void AutoNovel::Load()
{
	//アニメーション画像の読み込み
	anime.Load("texter/novel/button/auto_novel/0.png");
	anime.Load("texter/novel/button/auto_novel/1.png");
	anime.Load("texter/novel/button/auto_novel/2.png");
	anime.Load("texter/novel/button/auto_novel/3.png");
	anime.Load("texter/novel/button/auto_novel/4.png");
	anime.Load("texter/novel/button/auto_novel/5.png");
	anime.Load("texter/novel/button/auto_novel/6.png");
	anime.Load("texter/novel/button/auto_novel/7.png");

}

void AutoNovel::Init(VECTOR pos)
{
	button.Init(pos, VGet(64, 16, 0));//ボタンの初期化
	anime.Init(pos, 8);//アニメーションの初期化
	anime.SetAnimationSpeed(400);

	box.Init(VGet(pos.x, pos.y - 10, pos.z), VGet(0, 8, 0), GetColor(250, 250, 250));
	box.SetFill(true);
}

void AutoNovel::Update(DiploidEngineInput& input, int string_get_end_flag, float frame_time)
{
	anime.Update();//アニメーションのアップデート
	button.Updata(&input);//ボタンのアップデート

	if (button.GetSelectedUI() == 1)//選択状態のとき
	{
		//文字の描画が完了していたら
		if (string_get_end_flag == 1)
		{
			if (time >= target_time)
			{
				next_flag = true;//次へ行くflagを立てる
				time = 0;
			}
			else
			{
				next_flag = false;
				time += auto_speed * frame_time;//オートの時間を進める。
			}
		}
		else
		{
			//初期化
			next_flag = false;
			time = 0;
		}

	}
	else//選択状態でないとき
	{
		//初期化
		next_flag = false;
		time = 0;
	}	

	box.SetSize(VGet(time, 8, 0));//オートのtimeをビジュアルに反映
}

void AutoNovel::Draw(float frame_time, bool draw, bool debug)
{
	if (draw == true)
	{	
		box.Draw();

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


void AutoNovel::Reset()
{
	time = 0;
	button.SetSelectedUI(-1);
}


void AutoNovel::SetSpeed(float new_speed)
{
	auto_speed = new_speed;
}

void AutoNovel::SetSelected(int new_flag)
{
	button.SetSelectedUI(new_flag);
}


bool AutoNovel::GetHit()
{
	return button.GetHit();
}

bool AutoNovel::GetClick()
{
	return button.GetClick();
}

int AutoNovel::GetSelected()
{
	return button.GetSelectedUI();
}


bool AutoNovel::GetNextFlag()
{
	return next_flag;
}