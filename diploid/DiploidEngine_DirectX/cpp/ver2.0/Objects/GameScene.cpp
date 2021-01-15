#include "ver2.0/Objects/GameScene.h"

void GameScene::Load()
{
	jp.Load();

	string_back_wall.Load("texter/novel/basic/string_back_wall.png");
	data_back_wall.Load("texter/novel/basic/data_ui.png");
	data_test.Load("texter/novel/date/test.png");
	place_test.Load("texter/novel/place/test.png");

	novel_scene.Load("texter/novel/00.png", "1");
	novel_scene.Load("texter/novel/02.png", "2");

	anime.Load("texter/novel/icon/64_64/0.png");
	anime.Load("texter/novel/icon/64_64/1.png");
	anime.Load("texter/novel/icon/64_64/2.png");
	anime.Load("texter/novel/icon/64_64/3.png");

}

void GameScene::Init(DiploidEngineSetting& setting)
{
	//image_00.Init(VGet(0,0,0));
	novel_scene.Init(VGet(0, 0, 0));

	string_back_wall.Init(VGet(0, 0, 0));
	data_back_wall.Init(VGet(0, 0, 0));
	data_test.Init(VGet(0, 0, 0));
	place_test.Init(VGet(0, 0, 0));

	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	jp.SetSpeed(100);

	anime.Init(VGet(setting.window_x * 0.8f, setting.window_y - 64, 0),0.5f,0.5f);
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

	//場面切り替え
	switch (click)
	{
	case 0:	novel_scene.SetDrawName("1"); break;
	case 1:	novel_scene.SetDrawName("2"); break;
	case 2:	novel_scene.SetDrawName("1"); break;

	default: break;
	}

	novel_scene.Update();//場面切り替えのアップデート

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
	//image_00.Draw();
	novel_scene.Draw();

	data_back_wall.Draw();
	data_test.Draw();
	place_test.Draw();

	string_back_wall.Draw();

	if (box_draw_flag == 1)
	{
		jp.string[click].Draw();
	}

	if (jp.string[click].GetEnd() == 1)
	{
		anime.StackDraw();
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}