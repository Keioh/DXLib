#pragma once
#include <string>
#include <vector>
#include "DxLib.h"

class DiploidStrings
{
private:
	char strings[6][256];//実際に表示される文字列の配列
	char load_strings[5][256];//読み込んだ文字列
	int line = 0;//行
	int word_count = 0;//行のない文字列のカウント

	char font_name;
	int size;
	int thick;
	int end_flag = 0;//描画が終わったのかのフラグ

	int font_handle;
	float pos_x, pos_y;

	int count;//文字列配列の現在位置
	int next_time;//次の文字を表示する時間

	int next_speed = 0;//文字送りの速度

public:

	int CreateFontData(int Size, int Thick, int FontType, char *FontName = NULL);//DXLIBを参照
	int GetHandle();

	void Load(const char* str);//\nで改行、\fで文の終了を表す。GetEnd()関数を使用する場合は文の終わりに\fを付けること。(1行256文字、５改行まで)
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	void Reset();//文字配列の中を削除し、再び文字送り描画をします。(バグにつき使用不可)
	int GetEnd();//文字列の描画が終わったかのステータスを取得します。(1で描画終了、0で描画中)

	void SetSpeed(int speed);//文字送りの速度を設定します。

	void Draw(float x = 0, float y = 0);//Load関数で読み込んだ文字列を表示する。(1行256文字、５改行まで)
};