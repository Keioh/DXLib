#pragma once
#include <string>
#include <vector>
#include "DxLib.h"

class DiploidStrings
{
private:
	char strings[128];
	char load_strings[128];

	int font_handle;
	float pos_x, pos_y;

	int count;//文字列配列の現在位置
	int next_time;//次の文字を表示する時間

	int next_speed = 2;//文字送りの速度

public:

	int CreateFontData(int Size, int Thick, int FontType, char *FontName = NULL);//DXLIBを参照
	int GetHandle();

	void Load(const char* str);
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	void Reset();//文字配列の中を削除し、再び文字送り描画をします。

	void SetSpeed(int speed);//文字送りの速度を設定します。

	void Draw(float x = 0, float y = 0);//Load関数で読み込んだ文字列を表示する。(128文字まで)
	void DrawStrings(int x, int y, const char* str);//128文字まで

};