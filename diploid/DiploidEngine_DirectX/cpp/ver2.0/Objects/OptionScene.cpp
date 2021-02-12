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

	//Optionのタイトル画像
	option_string_image.Load();

	//OptionのDisplay画像
	display_string_image.Load();
	
	//OptionのGamePlay画像
	game_play_string_image.Load();


	string_speed_slider.Load();
	auto_speed_slider.Load();

	test_string.CreateFontData(20, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	test_string.Load("現在の表示速度です。\nThis is Test.");

	draw_speed_image.Load("texter/basic/option/game_play/draw_speed.png");
	auto_speed_image.Load("texter/basic/option/game_play/auto_speed.png");

}

void OptionScene::Init(DiploidEngineSetting& setting)
{	
	draw_speed_image.Init(VGet(string_speed_button_position_x, string_speed_button_position_y + 55 + (32 + 4), 0));
	string_speed_slider.Init(VGet(string_speed_button_position_x, string_speed_button_position_y + 55 + (32 + 4), 0), VGet(200, 0, 0));
	string_speed_slider.SetParameter(VGet(25, 0, 0));

	test_string.Init(string_speed_button_position_x, string_speed_button_position_y + (32 + 4));

	test_string_box.Init(VGet(string_speed_button_position_x + 152, string_speed_button_position_y + 36 + (32 + 4), 0), VGet(0, 8, 0), GetColor(100, 100, 100));
	test_string_box.SetFill(true);

	auto_speed_slider.Init(VGet(string_speed_button_position_x, string_speed_button_position_y + 95 + (32 + 4), 0), VGet(200, 0, 0));	
	auto_speed_image.Init(VGet(string_speed_button_position_x, string_speed_button_position_y + 95 + (32 + 4), 0));
	auto_speed_slider.SetParameter(VGet(50, 0, 0));


	//三角形の動的背景
	continuous_triangle.Init(VGet(0, 0, 0), 50, 100, 30);

	//Optionのタイトル画像
	option_string_image.Init(VGet(0, 0, 0));

	//OptionのDisplay画像
	display_string_image.Init(VGet(window_resize_button_position_x, window_resize_button_position_y, 0));

	//OptionのGamePlay画像
	game_play_string_image.Init(VGet(string_speed_button_position_x, string_speed_button_position_y, 0));

	//フェード用BOX
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	//戻るボタン
	back_button.Init(VGet(setting.window_x - (128 + 4), setting.window_y - (32 + 4), 0));

	//保存ボタン
	save_button.Init(VGet(setting.window_x - ((128 * 2) + 4), setting.window_y - (32 + 4), 0));

	//ウィンドウサイズ変更ボタン(960_540)
	window_resize_button_960_540.SetWindowSize(960, 540);//ターゲットとなるウィンドウサイズを指定
	window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);

	//ウィンドウサイズ変更ボタン(1280_720)
	window_resize_button_1280_720.SetWindowSize(1280, 720);//ターゲットとなるウィンドウサイズを指定
	window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);

	//ウィンドウサイズ変更ボタン(1600_900)	
	window_resize_button_1600_900.SetWindowSize(1600, 900);//ターゲットとなるウィンドウサイズを指定
	window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);

	//ウィンドウサイズ変更ボタン(1920_1080)	
	window_resize_button_1920_1080.SetWindowSize(1920, 1080);//ターゲットとなるウィンドウサイズを指定
	window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);
}

void OptionScene::Updata(DiploidEngineInput& input, DiploidEngineSetting& setting)
{
	SetBackgroundColor(255, 255, 255);//Window背景色を白色に変更

	string_speed_slider.Updata();
	auto_speed_slider.Updata();
	
	test_string.SetSpeed(string_speed_slider.GetParameter().x);

	if (next_flag == true)
	{
		test_string.Reset();//文字列データをリセットする
	}

	//文字の描画が完了していたら
	if (test_string.GetEnd() == 1)
	{
		if (time >= target_time)
		{
			next_flag = true;//次へ行くflagを立てる
			time = 0;
		}
		else
		{
			next_flag = false;
			time += auto_speed;//オートの時間を進める。
		}
	}
	else
	{
		next_flag = false;
	}

	auto_speed = auto_speed_slider.GetParameter().x / 100.0f;//オート速度を変更

	test_string_box.SetSize(VGet(time, 8, 0));//オートのtimeをビジュアルに反映


	//三角形の動的背景
	continuous_triangle.Updata(input);

	//Optionのタイトル画像
	option_string_image.Updata();

	//OptionのDisplay画像
	display_string_image.Updata();

	//OptionのGamePlay画像
	game_play_string_image.Updata();


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
		window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
		window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);
		window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
		window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);

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
	//三角形の動的背景
	continuous_triangle.Draw(draw, debug);

	string_speed_slider.Draw(draw, debug);
	test_string.Draw();
	draw_speed_image.Draw(draw);

	auto_speed_slider.Draw(draw, debug);
	test_string_box.Draw(draw);
	auto_speed_image.Draw(draw);

	//Optionのタイトル画像
	option_string_image.Draw(draw, debug);

	display_string_image.Draw(draw, debug);

	game_play_string_image.Draw(draw, debug);


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


	//DrawFormatString(300, 0, GetColor(0, 0, 0), "%d", window_resize_button_960_540.GetSelected());
	//DrawFormatString(300, 20, GetColor(0, 0, 0), "%d", window_resize_button_1280_720.GetSelected());
	//DrawFormatString(300, 40, GetColor(0, 0, 0), "%d", window_resize_button_1600_900.GetSelected());
	//DrawFormatString(300, 60, GetColor(0, 0, 0), "%d", window_resize_button_960_540.GetHit());
	//DrawFormatString(300, 80, GetColor(0, 0, 0), "%d", window_resize_button_960_540.GetClick());
	//DrawFormatString(300, 80, GetColor(0, 0, 0), "%f", test.GetParameter().x);

}


bool OptionScene::GetReturnFlag()
{
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		option_string_image.Reset();//Optionタイトル画像のアニメーションをリセット
		display_string_image.Reset();//Option:Display画像のアニメーションをリセット
		game_play_string_image.Reset();//Option:Display画像のアニメーションをリセット

		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);//ボタンの選択状態を-1(初期化)にする。
		return true;
	}

	return false;
}
