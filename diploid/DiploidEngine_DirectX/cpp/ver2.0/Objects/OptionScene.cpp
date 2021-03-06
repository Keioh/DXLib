#include "ver2.0/Objects/OptionScene.h"

void OptionScene::Load()
{
	//戻るボタンの読み込み
	back_button.Load();

	//保存ボタンの読み込み
	save_button.Load();

	//タイトルボタンの読み込み
	title_button.Load();

	//リセットボタンの読み込み
	reset_button.Load();


	//ウィンドウサイズ変更ボタンの画像読み込み
	window_resize_button_960_540.Load("texter/basic/button/display/960_540.png");
	window_resize_button_1280_720.Load("texter/basic/button/display/1280_720.png");
	window_resize_button_1600_900.Load("texter/basic/button/display/1600_900.png");
	window_resize_button_1920_1080.Load("texter/basic/button/display/1920_1080.png");

	//文字表示速度とオート速度の変更UI群
	text_speed_auto_setting_ui.Load();

	//Optionのタイトル画像
	option_string_image.Load();

	//OptionのDisplay画像
	display_string_image.Load();
	
	//OptionのGamePlay画像
	game_play_string_image.Load();

}

void OptionScene::Init(DiploidEngineSetting& setting)
{
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

	//タイトルボタン
	title_button.Init(VGet(setting.window_x - ((128 * 3) + 4), setting.window_y - (32 + 4), 0));

	//リセットボタン
	reset_button.Init(VGet(4, setting.window_y - (32 + 4), 0));



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

	//文字表示速度とオート速度の変更UI群
	text_speed_auto_setting_ui.Init(VGet(string_speed_button_position_x, string_speed_button_position_y, 0));
	text_speed_auto_setting_ui.SetParameterDrawSpeed(draw_speed);//文字描画速度
	text_speed_auto_setting_ui.SetParameterAutoSpeed(auto_speed);//オート速度
	text_speed_auto_setting_ui.SetParameterBackGroundAlpha(background_alpha);//透過度

}

void OptionScene::Updata(DiploidEngineInput& input, DiploidEngineSetting& setting, DiploidEngineScreen& screen, bool in_game_flag)
{
	SetBackgroundColor(0, 0, 0);//Window背景色を白色に変更

	in_game_flag_buffer = in_game_flag;//ゲーム中かのフラグを保存

	//三角形の動的背景
	continuous_triangle.Updata(input, screen);

	//Optionのタイトル画像
	option_string_image.Updata();

	//OptionのDisplay画像
	display_string_image.Updata();

	//OptionのGamePlay画像
	game_play_string_image.Updata();

	//文字表示速度とオート速度の変更UI群
	text_speed_auto_setting_ui.Update(screen);


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

		//文字描画速度とオート速度を変更して保存する。
		draw_speed = text_speed_auto_setting_ui.GetParameterAbsoluteDrawSpeed();//文字描画速度
		auto_speed = text_speed_auto_setting_ui.GetParameterAbsoluteAutoSpeed();//オート速度
		background_alpha = text_speed_auto_setting_ui.GetParameterAbsoluteBackGroundAlpha();//透過度
	}


	back_button.Update(input);//戻るボタンの更新処理

	if (back_button.GetClick() == true)//戻るボタンがクリックされたら
	{
		//現在の解像度のボタンにチェックを付けなおす。
		window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
		window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);
		window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
		window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);

		//文字描画速度とオート速度を保存した設定に戻す。
		text_speed_auto_setting_ui.SetParameterDrawSpeed(draw_speed);//文字描画速度
		text_speed_auto_setting_ui.SetParameterAutoSpeed(auto_speed);//オート速度
		text_speed_auto_setting_ui.SetParameterBackGroundAlpha(background_alpha);//透過度

		back_button.SetSelectedFlag(1);//選択状態を1を維持
		box_draw_flag = 2;//フェードインを始める
	}


	reset_button.Update(input);//リセットボタンの更新処理

	if (reset_button.GetClick() == true)//リセットボタンがクリックされたら
	{
		//文字描画速度とオート速度を1つ前に保存した設定に戻す。
		text_speed_auto_setting_ui.SetParameterDrawSpeed(draw_speed);//文字描画速度
		text_speed_auto_setting_ui.SetParameterAutoSpeed(auto_speed);//オート速度
		text_speed_auto_setting_ui.SetParameterBackGroundAlpha(background_alpha);//透過度

		//現在の解像度のボタンにチェックを付けなおす。
		window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
		window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);
		window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
		window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);
	}


	//ゲーム中のflagがtrueだったら
	if (in_game_flag_buffer == true)
	{
		title_button.Update(input);//タイトルボタンの更新処理

		if (title_button.GetClick() == true)//タイトルボタンがクリックされたら
		{
			//現在の解像度のボタンにチェックを付けなおす。
			window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
			window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);
			window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
			window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);

			//文字描画速度とオート速度を保存した設定に戻す。
			text_speed_auto_setting_ui.SetParameterDrawSpeed(draw_speed);//文字描画速度
			text_speed_auto_setting_ui.SetParameterAutoSpeed(auto_speed);//オート速度
			text_speed_auto_setting_ui.SetParameterBackGroundAlpha(background_alpha);//透過度

			title_button.SetSelectedFlag(1);//選択状態を1を維持
			box_draw_flag = 2;//フェードインを始める
		}
	}

	//シーンが始まったら
	if (box_draw_flag == 0)//フェードアウト始め
	{
		alpha -= alpha_speed * screen.GetFrameTime();//透過値を変更

		if (alpha <= 0)//透過値フロー処理
		{
			alpha = 0;
			box_draw_flag = 1;//フェードアウト完了
		}
	}

	if (box_draw_flag == 2)//フェードイン始め
	{
		alpha += alpha_speed * screen.GetFrameTime();//透過値を変更

		if (alpha > 255)//透過値フロー処理
		{
			alpha = 255;
			box_draw_flag = 3;//フェードイン完了
		}
	}
}

void OptionScene::Draw(DiploidEngineScreen& screen, bool draw, bool debug)
{	
	//三角形の動的背景
	continuous_triangle.Draw(draw, debug);

	//Optionのタイトル画像
	option_string_image.Draw(draw, debug);

	//OptionのDisplay画像
	display_string_image.Draw(draw, debug);

	//OptionのGamePlay画像
	game_play_string_image.Draw(draw, debug);


	//ウィンドウサイズ変更ボタン(960_540)
	window_resize_button_960_540.Draw(draw, debug);

	//ウィンドウサイズ変更ボタン(1280_720)
	window_resize_button_1280_720.Draw(draw, debug);

	//ウィンドウサイズ変更ボタン(1600_900)
	window_resize_button_1600_900.Draw(draw, debug);

	//ウィンドウサイズ変更ボタン(1920_1080)
	window_resize_button_1920_1080.Draw(draw, debug);

	//文字表示速度とオート速度の変更UI群
	text_speed_auto_setting_ui.Draw(screen.GetFrameTime(), draw, debug);


	//保存ボタン
	save_button.Draw(screen.GetFrameTime(), draw, debug);

	//戻るボタン
	back_button.Draw(screen.GetFrameTime(), draw, debug);

	//リセットボタン
	reset_button.Draw(screen.GetFrameTime(), draw, debug);

	//タイトルボタン
	if (in_game_flag_buffer == true)
	{
		title_button.Draw(screen.GetFrameTime(), draw, debug);
	}

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


int OptionScene::GetReturnFlag()
{
	//ゲーム中でない、かつ戻るボタンを押したら
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3) && (in_game_flag_buffer == false))
	{
		option_string_image.Reset();//Optionタイトル画像のアニメーションをリセット
		display_string_image.Reset();//Option:Display画像のアニメーションをリセット
		game_play_string_image.Reset();//Option:Display画像のアニメーションをリセット

		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);//ボタンの選択状態を-1(初期化)にする。
		title_button.SetSelectedFlag(-1);
		return GAME_TITLE;//タイトルに戻る
	}

	//ゲーム中かつ戻るボタンを押したら
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3) && (in_game_flag_buffer == true))
	{
		option_string_image.Reset();//Optionタイトル画像のアニメーションをリセット
		display_string_image.Reset();//Option:Display画像のアニメーションをリセット
		game_play_string_image.Reset();//Option:Display画像のアニメーションをリセット

		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);//ボタンの選択状態を-1(初期化)にする。
		title_button.SetSelectedFlag(-1);
		return GAME_START;//ゲームに戻る
	}

	//ゲーム中かつタイトルボタンを押したら
	if ((title_button.GetSelected() == 1) && (box_draw_flag == 3) && (in_game_flag_buffer == true))
	{
		option_string_image.Reset();//Optionタイトル画像のアニメーションをリセット
		display_string_image.Reset();//Option:Display画像のアニメーションをリセット
		game_play_string_image.Reset();//Option:Display画像のアニメーションをリセット

		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);//ボタンの選択状態を-1(初期化)にする。
		title_button.SetSelectedFlag(-1);
		return GAME_TITLE;//タイトルに戻る
	}

	return GAME_NONE;
}
