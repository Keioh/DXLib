#include "ver2.0/Objects/FileScene.h"

void FileScene::Load()
{
	load_string_image.Load();

	back_button.Load();
}

void FileScene::Init()
{
	//フェード用BOX
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	load_string_image.Init(VGet(0, 0, 0));


	//戻るボタン
	back_button.Init(VGet(setting.window_x - (128 + 4), setting.window_y - (32 + 4), 0));
}

void FileScene::Updata()
{
	SetBackgroundColor(255, 255, 255);

	load_string_image.Updata();

	//戻るボタン
	back_button.Update(input);

	//フェードアウト完了していたら
	if (box_draw_flag == 1)
	{
		//戻るボタンをクリックしたら
		if (back_button.GetClick() == true)
		{
			back_button.SetSelectedFlag(1);
			box_draw_flag = 2;
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

	if (box_draw_flag == 2)//フェードイン始め
	{
		alpha += alpha_speed;//透過値を変更

		if (alpha > 255)//透過値フロー処理
		{
			alpha = 255;
			box_draw_flag = 3;//フェードイン完了
		}
	}


	if (mosaic >= mosaic_max)//モザイク値フロー処理
	{
		mosaic = mosaic_max;
	}
	else
	{
		mosaic += mosaic_speed;//モザイク値を変更
	}
}

void FileScene::Draw()
{
	load_string_image.Draw();

	//戻るボタン
	back_button.Draw();

	//モザイク処理
	//scr_gra.Draw(mosaic);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

int FileScene::GetReturnButton()
{
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		load_string_image.Reset();

		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);
		return GAME_TITLE;
	}

	return GAME_NONE;
}

void FileScene::SetSecne(int scene_type)
{
	secen_select = scene_type;
	button_click = scene_type;
}