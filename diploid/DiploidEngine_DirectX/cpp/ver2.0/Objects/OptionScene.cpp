#include "ver2.0/Objects/OptionScene.h"

void OptionScene::Load()
{
	//戻るボタンの読み込み
	back_button.Load();

	//保存ボタンの読み込み
	save_button.Load();

	//ウィンドウサイズ変更ボタンの画像読み込み
	window_resize_button_960_540.Load("texter/basic/button/display/960_540.png");
	window_resize_button_1280_720.Load("texter/basic/button/display/1280_720.png");
	window_resize_button_1600_900.Load("texter/basic/button/display/1600_900.png");
	window_resize_button_1920_1080.Load("texter/basic/button/display/1920_1080.png");

}

void OptionScene::Init(DiploidEngineSetting& setting)
{
	//フェード用BOX
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	//戻るボタン
	back_button.Init(VGet(setting.window_x - (128 + 4), setting.window_y - (32 + 4), 0));

	//保存ボタン
	save_button.Init(VGet(setting.window_x - ((128 * 2) + 4), setting.window_y - (32 + 4), 0));

	//ウィンドウサイズ変更ボタン(960_540)
	window_resize_button_960_540.SetWindowSize(960, 540);//ターゲットとなるウィンドウサイズを指定
	window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y, 0), setting);

	//ウィンドウサイズ変更ボタン(1280_720)
	window_resize_button_1280_720.SetWindowSize(1280, 720);//ターゲットとなるウィンドウサイズを指定
	window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);

	//ウィンドウサイズ変更ボタン(1600_900)	
	window_resize_button_1600_900.SetWindowSize(1600, 900);//ターゲットとなるウィンドウサイズを指定
	window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 2), 0), setting);

	//ウィンドウサイズ変更ボタン(1920_1080)	
	window_resize_button_1920_1080.SetWindowSize(1920, 1080);//ターゲットとなるウィンドウサイズを指定
	window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
}

void OptionScene::Updata(DiploidEngineInput& input, DiploidEngineSetting& setting)
{
	SetBackgroundColor(255, 255, 255);//Window背景色を白色に変更

	//ウィンドウサイズ変更ボタン(960_540)
	window_resize_button_960_540.Update(input);

	//ウィンドウサイズ変更ボタン(1280_720)
	window_resize_button_1280_720.Update(input);

	//ウィンドウサイズ変更ボタン(1600_900)
	window_resize_button_1600_900.Update(input);

	//ウィンドウサイズ変更ボタン(1920_1080)
	window_resize_button_1920_1080.Update(input);


	//ウィンドウサイズ変更ボタン(960_540)がクリックされたとき
	if (window_resize_button_960_540.GetClick() == true)
	{
		window_resize_button_960_540.SetSelectedFlag(1);

		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//ウィンドウサイズ変更ボタン(1280_720)がクリックされたとき
	if (window_resize_button_1280_720.GetClick() == true)
	{
		window_resize_button_1280_720.SetSelectedFlag(1);

		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//ウィンドウサイズ変更ボタン(1600_900)がクリックされたとき
	if (window_resize_button_1600_900.GetClick() == true)
	{
		window_resize_button_1600_900.SetSelectedFlag(1);	
		
		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//ウィンドウサイズ変更ボタン(1920_1080)がクリックされたとき
	if (window_resize_button_1920_1080.GetClick() == true)
	{
		window_resize_button_1920_1080.SetSelectedFlag(1);

		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
	}


	save_button.Update(input);//保存ボタンの更新処理

	if ((save_button.GetClick() == true) && (save_button.GetHit() == true))//保存ボタンを押したとき
	{
		//ウィンドウサイズ960_540が選択状態なら
		if (window_resize_button_960_540.GetSelected() == 1)
		{
			setting.SetWindowSize(960, 540);//解像度を変更
		}

		//ウィンドウサイズ1280_720が選択状態なら
		if (window_resize_button_1280_720.GetSelected() == 1)
		{
			setting.SetWindowSize(1280, 720);//解像度を変更
		}

		//ウィンドウサイズ1600_900が選択状態なら
		if (window_resize_button_1600_900.GetSelected() == 1)
		{
			setting.SetWindowSize(1600, 900);//解像度を変更
		}

		//ウィンドウサイズ1920_1080が選択状態なら
		if (window_resize_button_1920_1080.GetSelected() == 1)
		{
			setting.SetWindowSize(1920, 1080);//解像度を変更
		}
	}


	back_button.Update(input);//戻るボタンの更新処理

	if (back_button.GetClick() == true)//戻るボタンがクリックされたら
	{
		//現在の解像度のボタンにチェックを付けなおす。
		window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y, 0), setting);
		window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
		window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 2), 0), setting);
		window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);

		back_button.SetSelectedFlag(1);//選択状態を1を維持
		box_draw_flag = 2;//フェードインを始める
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
}

void OptionScene::Draw(bool draw, bool debug)
{	
	//ウィンドウサイズ変更ボタン(960_540)
	window_resize_button_960_540.Draw(draw, debug);

	//ウィンドウサイズ変更ボタン(1280_720)
	window_resize_button_1280_720.Draw(draw, debug);

	//ウィンドウサイズ変更ボタン(1600_900)
	window_resize_button_1600_900.Draw(draw, debug);

	//ウィンドウサイズ変更ボタン(1920_1080)
	window_resize_button_1920_1080.Draw(draw, debug);


	//保存ボタン
	save_button.Draw(draw, debug);

	//戻るボタン
	back_button.Draw(draw, debug);

	//フェードアウト用BOX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}


bool OptionScene::GetReturnFlag()
{
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);//ボタンの選択状態を-1(初期化)にする。
		return true;
	}

	return false;
}
