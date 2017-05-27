#pragma once
#include "DxLib.h"
#include "System.h"

class DICE
{
private:
	int font_size;//フォントの大きさ
	int font_thick;//フォントの太さ
	int font_handl;//フォントハンドル

	int critical_init;//クリティカルの判定数の決定
	int fumble_init;//ファンブルの判定数の決定

	int graph_1D100;
	int graph_1D100_hit;
	int graph_critical;
	int graph_fumble;

	int mouse_x, mouse_y;//マウスカーソルの位置

public:
	DICE();
	int seed_count;//randシードの変更変数
	int oneDhundred;//1d100の結果を保存する変数。
	int customDcustom;//?d?の結果を保存する変数。
	int start;
	int end;

	bool oneD100_click;//1d100を押したかどうかのフラグ
	int graph_drawing_flag;//クリファン画像を表示するかどうかのフラグ

	void init();
	void Load();

	int Dice_role_oneDhundred(int x, int y);//1d100のダイスロール
	int Dice_role_custom(int x, int y);//?d?のダイスロール

	void Critical_Fumble_Screen();//クリとファングルの画像表示と判定。
};