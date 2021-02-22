#include "ver2.0/Objects/button/Reset.h"

void Reset::Load()
{
	return_button_animation.Load("texter/novel/button/reset/0.png");
	return_button_animation.Load("texter/novel/button/reset/1.png");
	return_button_animation.Load("texter/novel/button/reset/2.png");
	return_button_animation.Load("texter/novel/button/reset/3.png");
	return_button_animation.Load("texter/novel/button/reset/4.png");
	return_button_animation.Load("texter/novel/button/reset/5.png");
}

void Reset::Init(VECTOR pos)
{
	return_button_animation.Init(pos, 6);
	return_button_animation.SetAnimationSpeed(300);

	return_button.Init(pos, VGet(128, 32, 0));
}

void Reset::Update(DiploidEngineInput& input)
{
	return_button_animation.Update();
	return_button.Updata(&input);
}

void Reset::Draw(float frame_time, bool draw, bool debug)
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


bool Reset::GetHit()
{
	return return_button.GetHit();
}

bool Reset::GetClick()
{
	return return_button.GetClick();
}

int Reset::GetSelected()
{
	return return_button.GetSelectedUI();
}


void Reset::SetSelectedFlag(int new_flag)
{
	return_button.SetSelectedUI(new_flag);
}