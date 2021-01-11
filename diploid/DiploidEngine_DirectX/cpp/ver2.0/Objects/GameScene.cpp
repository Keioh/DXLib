#include "ver2.0/Objects/GameScene.h"

void GameScene::Load()
{
	jp.Load();

	image_00.Load("texter/novel/00.png");

	anime.Load("texter/novel/icon/128_128/0.png");
	anime.Load("texter/novel/icon/128_128/1.png");
	anime.Load("texter/novel/icon/128_128/2.png");
	anime.Load("texter/novel/icon/128_128/3.png");
	anime.Load("texter/novel/icon/128_128/4.png");
	anime.Load("texter/novel/icon/128_128/5.png");
	anime.Load("texter/novel/icon/128_128/6.png");
	anime.Load("texter/novel/icon/128_128/7.png");
	anime.Load("texter/novel/icon/128_128/8.png");
	anime.Load("texter/novel/icon/128_128/9.png");

}

void GameScene::Init(DiploidEngineSetting& setting)
{
	image_00.Init(VGet(0,0,0));

	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	jp.SetSpeed(100);

	anime.Init(VGet(0, 0, 0),0.5f,0.5f);
}

void GameScene::Updata(DiploidEngineInput& input)
{
	if (box_draw_flag == 1)//フェードアウト完了していたら
	{
		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			if (jp.string[click].GetEnd() == 0)//最後まで表示されていなかったら
			{
				jp.string[click].AllIn();//最後の文字まで表示
			}
			else
			{
				if ((jp.string.size() - 1) != click)
				{
					click++;//次の文を表示
				}
			}
		}
	}

	//シーンが始まったら
	if (box_draw_flag == 0)//フェードアウト始め
	{
		alpha -= alpha_speed;//透過値を変更

		if (alpha <= 0)//透過値フロー処理
		{
			alpha = 0;
			box_draw_flag = 1;//フェードアウト完了
		}
	}
	
	if(box_draw_flag == 2)//フェードイン始め
	{	
		alpha -= alpha_speed;//透過値を変更

		if (alpha > 255)//透過値フロー処理
		{
			alpha = 255;
			box_draw_flag = 3;//フェードイン完了
		}
	}
}

void GameScene::Draw()
{
	image_00.Draw();

	if (box_draw_flag == 1)
	{
		jp.string[click].Draw();
	}

	anime.StackDraw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}