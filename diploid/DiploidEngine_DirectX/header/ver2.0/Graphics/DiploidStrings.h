#pragma once
#include <string>
#include <vector>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"


class DiploidStrings
{
private:
	char string[512];//出力用
	char load_string[512];//読み込み用

	char font_name;
	int size;
	int thick;
	int line_spacing = 10;
	int end_flag = 0;//描画が終わったのかのフラグ
	int string_all = 0;//現在の文字の位置を保存

	int font_handle;
	float pos_x, pos_y;

	int count = 0;//文字列配列の現在位置
	int next_time = 100;//次の文字を表示する時間
	int time;//時間保存用

	int next_speed = 50;//文字送りの速度

	bool complete = false;//既読済みかどうか(trueで既読)

	std::string scene_number;


public:

	int CreateFontData(int Size, int Thick, int FontType, char *FontName = NULL);//DXLIBを参照
	int GetHandle();

	void Load(const char* str = "");//\nで改行を表す。(1行512文字、５改行まで)
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	void Reset();//文字配列の中を削除し、再び文字送り描画をします。
	int GetEnd();//文字列の描画が終わったかのステータスを取得します。(1で描画終了、0で描画中)
	std::string GetSceneName();
	void SetSceneName(std::string name);

	void AllIn();//全ての文字を表示します。(読み込んだ文字列を全て表示用配列にコピーします。)
	bool GetCompleteFlag();//既読かどうかのフラグを得ます。
	void SetCompleteFlag(bool new_flag);

	void SetLineSpaceing(int space);
	void SetSpeed(int speed);//文字送りの速度を設定します。

	void Draw();//Load関数で読み込んだ文字列を表示する。(1行512文字)
};