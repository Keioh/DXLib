#include "ver2.0/Objects/TitleScene.h"

void TitleScene::Load()
{
	button_back_image.Load("texter/title/button_back.png");//ボタンの背景画像の読み込み
	test_back.Load("texter/hd.jpg");//testの背景画像の読み込み

	start_button.Load(button_back_image.GetGraphicsHandl());//スタートボタンの画像ハンドルの読み込み
	load_button.Load(button_back_image.GetGraphicsHandl());//セーブデータ読み込みボタンの画像ハンドルの読み込み
	option_button.Load(button_back_image.GetGraphicsHandl());//オプションボタンの画像ハンドルの読み込み
	exit_button.Load(button_back_image.GetGraphicsHandl());//終了ボタンの画像ハンドルの読み込み。


	start_string.CreateFontData(50, 5, DX_FONTTYPE_NORMAL);//フォント作成

	//文字の読み込み
	start_string.Load("Start");//スタートボタンの文字列の設定

	load_string.Load("Load");
	load_string.ChangeFont(start_string.GetHandle());

	option_string.Load("Option");
	option_string.ChangeFont(start_string.GetHandle());

	exit_string.Load("Exit");//終了ボタンの文字列の設定
	exit_string.ChangeFont(start_string.GetHandle());//終了ボタンの文字列にスタートボタンで使用したフォントを使用する。

}

void TitleScene::Init()
{
	//フェードイン、アウト用のBOXの初期化
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	//各種ボタンの配置位置を設定
	start_button.Init(VGet(128, setting.window_y - 512, 0), button_back_image.GetSize());//スタートボタンの初期化
	load_button.Init(VGet(128, setting.window_y - 512 + (button_back_image.GetSize().y + 20), 0), button_back_image.GetSize());//読み込みボタンの初期化
	option_button.Init(VGet(128, setting.window_y - 512 + (button_back_image.GetSize().y + 20) * 2, 0), button_back_image.GetSize());//オプションボタンの初期化
	exit_button.Init(VGet(128, setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 3), 0), button_back_image.GetSize());//終了ボタンの初期化
}

void TitleScene::Updata()
{
	SetBackgroundColor(0, 0, 0);

	//各ボタンのアップデート
	start_button.Updata(&input);
	load_button.Updata(&input);
	option_button.Updata(&input);
	exit_button.Updata(&input);


	if (alpha <= 0)//透過値フロー処理
	{
		alpha = 0;
	}
	else
	{		
		alpha -= alpha_speed;//透過値を変更
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

void TitleScene::Draw()
{
	test_back.Draw();

	start_button.Draw();
	start_string.Draw(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512);

	load_button.Draw();
	load_string.Draw(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512 + (button_back_image.GetSize().y + 20));

	option_button.Draw();
	option_string.Draw(128 + (button_back_image.GetSize().x / 4), setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 2));

	exit_button.Draw();
	exit_string.Draw(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 3));

	scr_gra.Draw(mosaic);


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

int TitleScene::GetFinalScene()
{
	//スタートボタンを押した
	if (start_button.GetClick() == true)
	{		
		start_button.SetSelectedUI(false);
		return GAME_START;
	}

	//読み込みボタンを押した
	if (load_button.GetClick() == true)
	{	
		load_button.SetSelectedUI(false);
		return GAME_LOAD;
	}

	//オプションボタンを押した
	if (option_button.GetClick() == true)
	{
		option_button.SetSelectedUI(false);
		return GAME_OPTION;
	}

	//ゲーム終了ボタンを押した。
	if (exit_button.GetClick() == true)
	{	
		exit_button.SetSelectedUI(false);
		return GAME_EXIT;
	}

	return GAME_NONE;
}