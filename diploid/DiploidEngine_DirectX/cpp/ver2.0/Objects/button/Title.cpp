#include "ver2.0/Objects/button/Title.h"

void Title::Load()
{
	return_button_animation.Load("texter/novel/button/title/0.png");
	return_button_animation.Load("texter/novel/button/title/1.png");
	return_button_animation.Load("texter/novel/button/title/2.png");
	return_button_animation.Load("texter/novel/button/title/3.png");
	return_button_animation.Load("texter/novel/button/title/4.png");
	return_button_animation.Load("texter/novel/button/title/5.png");
	return_button_animation.Load("texter/novel/button/title/6.png");
	return_button_animation.Load("texter/novel/button/title/7.png");
}

void Title::Init(VECTOR pos)
{
	return_button_animation.Init(pos, 8);
	return_button_animation.SetAnimationSpeed(300);

	return_button.Init(pos, VGet(128, 32, 0));
}

void Title::Update(DiploidEngineInput& input)
{
	return_button_animation.Update();
	return_button.Updata(&input);
}

void Title::Draw(float frame_time, bool draw, bool debug)
{
	if (draw == true)
	{
		//ボタンに触れていたら
		if (return_button.GetHit() == true)
		{
			SetDrawBright(255, 255, 255);
			//アニメーションを再生
			return_button_animation.Draw(frame_time);
			//return_button_animation.StackDraw();

		}
		else//ボタンに触れていなかったら
		{
			SetDrawBright(255 * 0.8, 255 * 0.8, 255 * 0.8);

			//アニメーションのリセット
			return_button_animation.Reset();

			//０コマ目を表示
			return_button_animation.OneCellDraw();

			SetDrawBright(255, 255, 255);
		}
	}

	if (debug == true)
	{
		return_button.Draw();
	}
}


bool Title::GetHit()
{
	return return_button.GetHit();
}

bool Title::GetClick()
{
	return return_button.GetClick();
}

int Title::GetSelected()
{
	return return_button.GetSelectedUI();
}


void Title::SetSelectedFlag(int new_flag)
{
	return_button.SetSelectedUI(new_flag);
}