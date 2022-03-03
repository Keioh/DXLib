#pragma once
#include <string>
#include "DxLib.h"

//#include "data/system_data/system_data.h"

struct SystemData
{
	//言語の設定
	std::string language;//言語

	//Window設定関連
	int window_x;//実際のウィンドウサイズ(ｘ)
	int window_y;//実際のウィンドウサイズ(ｙ)
	int simulation_window_x;//シミュレートのウィンドウサイズ(ｘ)
	int simulation_window_y;//シミュレートのウィンドウサイズ(ｙ)
	int refreshrate;//リフレッシュレート
	bool window_mode;//フルスクリーンか
	bool vsync;//垂直同期を待つか

	bool shadow_map;//シャドウマップを表示するか

	int shadow_map_size_x;//シャドウマップの大きさ(x)
	int shadow_map_size_y;//シャドウマップの大きさ(y)

	float shadow_map_min_area_x;//シャドウマップの最少描画範囲
	float shadow_map_min_area_y;
	float shadow_map_min_area_z;

	float shadow_map_max_area_x;//シャドウマップの最大描画範囲
	float shadow_map_max_area_y;
	float shadow_map_max_area_z;


	//文字描画設定関連
	float string_draw_speed;//文字の描画速度
	float string_auto_speed;//文字のオート速度
	float string_background_alpha;//文字の背景透過度
};