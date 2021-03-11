#pragma once
#include "DxLib.h"

//#include "data/system_data/system_data.h"

struct SystemData
{
	//Window設定関連
	int window_x;//実際のウィンドウサイズ(ｘ)
	int window_y;//実際のウィンドウサイズ(ｙ)
	int simulation_window_x;//シミュレートのウィンドウサイズ(ｘ)
	int simulation_window_y;//シミュレートのウィンドウサイズ(ｙ)
	int refreshrate;//リフレッシュレート
	bool window_mode;//フルスクリーンか
	bool vsync;//垂直同期を待つか

	//文字描画設定関連
	float string_draw_speed;//文字の描画速度
	float string_auto_speed;//文字のオート速度
	float string_background_alpha;//文字の背景透過度
};