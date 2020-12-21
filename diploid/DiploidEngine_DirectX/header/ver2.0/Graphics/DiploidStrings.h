#pragma once
#include <string>
#include <vector>
#include "DxLib.h"

class DiploidStrings
{
private:
	char strings[6][512];//実際に表示される文字列の配列
	char load_strings[5][512];//読み込んだ文字列
	char string_data[512];//バグ回避用文字送りなし配列用
	int line = 0;//行
	int word_count = 0;//行のない文字列のカウント
	int line_count = 0;

	char font_name;
	int size;
	int thick;
	int line_spacing = 10;
	int end_flag = 0;//描画が終わったのかのフラグ

	int font_handle;
	float pos_x, pos_y;

	int count = 0;//文字列配列の現在位置
	int next_time;//次の文字を表示する時間

	int next_speed = 0;//文字送りの速度

	bool test = true;

public:

	int CreateFontData(int Size, int Thick, int FontType, char *FontName = NULL);//DXLIBを参照
	int GetHandle();

	void Load(const char* str = "");//\nで改行を表す。(1行512文字、５改行まで)
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	void Reset();//文字配列の中を削除し、再び文字送り描画をします。(バグにつき使用不可)
	int GetEnd();//文字列の描画が終わったかのステータスを取得します。(1で描画終了、0で描画中)

	void AllIn();//全ての文字を表示します。(読み込んだ文字列を全て表示用配列にコピーします。)

	void SetLineSpaceing(int space);
	void SetSpeed(int speed);//文字送りの速度を設定します。

	void Draw();//Load関数で読み込んだ文字列を表示する。(1行512文字、５改行まで)
};