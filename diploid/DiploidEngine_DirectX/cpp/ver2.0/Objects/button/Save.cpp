#include "ver2.0/Objects/button/Save.h"

void Save::Load()
{
	button_animation.Load("texter/novel/button/save/0.png");
	button_animation.Load("texter/novel/button/save/1.png");
	button_animation.Load("texter/novel/button/save/2.png");
	button_animation.Load("texter/novel/button/save/3.png");
	button_animation.Load("texter/novel/button/save/4.png");
	button_animation.Load("texter/novel/button/save/5.png");
	button_animation.Load("texter/novel/button/save/6.png");
	button_animation.Load("texter/novel/button/save/7.png");
	button_animation.Load("texter/novel/button/save/8.png");
	button_animation.Load("texter/novel/button/save/9.png");
	button_animation.Load("texter/novel/button/save/10.png");
	button_animation.Load("texter/novel/button/save/11.png");
	button_animation.Load("texter/novel/button/save/12.png");
	button_animation.Load("texter/novel/button/save/13.png");
}

void Save::Init(VECTOR pos)
{
	button_animation.Init(pos, 14);
	button_animation.SetAnimationSpeed(500);

	button.Init(pos, VGet(128, 32, 0));
}

void Save::Update(DiploidEngineInput& input)
{
	//button_animation.Update();
	button.Updata(&input);
}

void Save::Draw(float frame_time, bool draw, bool debug)
{
	if (draw == true)
	{
		//ボタンに触れていたら
		if (button.GetHit() == true)
		{
			if (button.GetClick() == true)
			{
				SetDrawBright(255, 255, 255);
			}
			else
			{
				SetDrawBright(255 * 0.9, 255 * 0.9, 255 * 0.9);
			}

			//アニメーションを再生
			button_animation.Draw(frame_time);
			//button_animation.StackDraw();

			SetDrawBright(255, 255, 255);

		}
		else//ボタンに触れていなかったら
		{
			SetDrawBright(255 * 0.8, 255 * 0.8, 255 * 0.8);

			//アニメーションのリセット
			button_animation.Reset();

			//０コマ目を表示
			button_animation.OneCellDraw();

			SetDrawBright(255, 255, 255);
		}


	}

	if (debug == true)
	{		
		button.Draw(true, true);	
		//DrawFormatString(0, 100, GetColor(0, 0, 0), "size = %d", button_animation.GetImagesVectorSize());
	}
}


bool Save::GetHit()
{
	return button.GetHit();
}

bool Save::GetClick()
{
	return button.GetClick();
}

int Save::GetSelected()
{
	return button.GetSelectedUI();
}


void Save::SetSelectedFlag(int new_flag)
{
	button.SetSelectedUI(new_flag);
}

void Save::SetPosition(VECTOR new_pos)
{
	button_animation.SetPosition(new_pos);
	button.SetPosition(new_pos.x, new_pos.y);
}