#include "ver2.0/Objects/OptionScene.h"

void OptionScene::Load()
{
	return_button_animation.Load("texter/novel/button/back/0.png");
	return_button_animation.Load("texter/novel/button/back/1.png");
	return_button_animation.Load("texter/novel/button/back/2.png");
	return_button_animation.Load("texter/novel/button/back/3.png");
	return_button_animation.Load("texter/novel/button/back/4.png");
	return_button_animation.Load("texter/novel/button/back/5.png");
	return_button_animation.Load("texter/novel/button/back/6.png");
	return_button_animation.Load("texter/novel/button/back/7.png");
	return_button_animation.Load("texter/novel/button/back/8.png");
	return_button_animation.Load("texter/novel/button/back/9.png");
	return_button_animation.Load("texter/novel/button/back/10.png");
	return_button_animation.Load("texter/novel/button/back/11.png");
	return_button_animation.Load("texter/novel/button/back/12.png");
	return_button_animation.Load("texter/novel/button/back/13.png");
	return_button_animation.Load("texter/novel/button/back/14.png");
	return_button_animation.Load("texter/novel/button/back/15.png");
	return_button_animation.Load("texter/novel/button/back/16.png");
	return_button_animation.Load("texter/novel/button/back/17.png");

}

void OptionScene::Init(DiploidEngineSetting& setting)
{
	return_button_animation.Init(VGet(setting.window_x - 128, setting.window_y - (32 + 4), 0.0f));
	return_button_animation.SetAnimationSpeed(10);

	return_button.Init(VGet(setting.window_x - 128, setting.window_y -  (32 + 4), 0.0f), VGet(128,32,0));
}

void OptionScene::Updata(DiploidEngineInput& input)
{
	SetBackgroundColor(255, 255, 255);

	return_button_animation.Update();
	return_button.Updata(&input);
}

void OptionScene::Draw(bool draw, bool debug)
{
	if (draw == true)
	{
		//ボタンに触れていたら
		if (return_button.GetHit() == true)
		{
			SetDrawBright(255, 255, 255);
			//アニメーションを再生
			return_button_animation.StackDraw();
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


bool OptionScene::GetReturnFlag()
{
	if (return_button.GetHit() == true)
	{
		return return_button.GetClick();
	}

	return false;
}