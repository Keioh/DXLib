#include "ver2.0/Objects/TitleScene.h"

void TitleScene::Load()
{
	button_back_image.Load("texter/title/button_back.png");//ボタンの背景画像の読み込み
	test_back.Load("texter/hd.jpg");//testの背景画像の読み込み

	start_button.Load(button_back_image.GetGraphicsHandl());//スタートボタンの画像ハンドルの読み込み
	load_button.Load(button_back_image.GetGraphicsHandl());//セーブデータ読み込みボタンの画像ハンドルの読み込み
	option_button.Load(button_back_image.GetGraphicsHandl());//オプションボタンの画像ハンドルの読み込み
	exit_button.Load(button_back_image.GetGraphicsHandl());//終了ボタンの画像ハンドルの読み込み。


	start_string.CreateFontData(50, 10, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);//フォント作成

	//文字の読み込み
	start_string.Load("Start");//スタートボタンの文字列の設定
	load_string.Load("Load");
	option_string.Load("Option");
	exit_string.Load("Exit");//終了ボタンの文字列の設定
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

	start_string.Init(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512, start_string.GetHandle());
	start_string.SetSpeed(5000);
	load_string.Init(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512 + (button_back_image.GetSize().y + 20), start_string.GetHandle());
	load_string.SetSpeed(5000);
	option_string.Init(128 + (button_back_image.GetSize().x / 4), setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 2), start_string.GetHandle());
	option_string.SetSpeed(5000);
	exit_string.Init(128 + (button_back_image.GetSize().x / 3), setting.window_y - 512 + ((button_back_image.GetSize().y + 20) * 3), start_string.GetHandle());
	exit_string.SetSpeed(5000);
}

void TitleScene::Updata(DiploidEngineScreen& screen)
{
	SetBackgroundColor(0, 0, 0);

	//各ボタンのアップデート
	start_button.Updata(&input);
	load_button.Updata(&input);
	option_button.Updata(&input);
	exit_button.Updata(&input);

	//どのボタンも押されていなかったら
	if (button_click == GAME_TITLE)
	{
		//スタートボタンを押した
		if (start_button.GetClick() == true)
		{
			start_button.SetSelectedUI(false);
			button_click = GAME_START;
		}

		//読み込みボタンを押した
		if (load_button.GetClick() == true)
		{
			load_button.SetSelectedUI(false);
			button_click = GAME_FILE;
		}

		//オプションボタンを押した
		if (option_button.GetClick() == true)
		{
			option_button.SetSelectedUI(false);
			button_click = GAME_OPTION;
		}

		//ゲーム終了ボタンを押した。
		if (exit_button.GetClick() == true)
		{
			exit_button.SetSelectedUI(false);
			button_click = GAME_EXIT;
		}
	}

	//ボタンを押したら
	if (button_click != GAME_TITLE)
	{
		alpha += alpha_speed * screen.GetFrameTime();//透過値を変更

		if (alpha > 255)//透過値フロー処理
		{
			alpha = 255;
			secen_select = button_click;//押したボタンのシーン種類を代入
		}
	}
	else
	{
		if (alpha <= 0)//透過値フロー処理
		{
			alpha = 0;
		}
		alpha -= alpha_speed * screen.GetFrameTime();//透過値を変更
	}


	if (mosaic >= mosaic_max)//モザイク値フロー処理
	{
		mosaic = mosaic_max;
	}
	else
	{
		mosaic += mosaic_speed * screen.GetFrameTime();//モザイク値を変更
	}
}

void TitleScene::Draw(DiploidEngineScreen& screen)
{
	test_back.Draw();

	start_button.Draw();
	start_string.Draw(screen.GetFrameTime());

	load_button.Draw();
	load_string.Draw(screen.GetFrameTime());

	option_button.Draw();
	option_string.Draw(screen.GetFrameTime());

	exit_button.Draw();
	exit_string.Draw(screen.GetFrameTime());

	//モザイク処理
	//scr_gra.Draw(mosaic);


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

int TitleScene::GetFinalScene()
{
	return secen_select;
}

void TitleScene::SetSecne(int scene_type)
{
	secen_select = scene_type;
	button_click = scene_type;
}