#pragma once
#include <string>
#include <vector>
//#include <climits>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "diploidInput\DiploidEnigneFile.h"


struct FONT_INFO
{
	int font_handle;
	char font_name[32];
	int size;
	int thick;

};

class DiploidStringV2
{
private:
	DiploidEngineFile file;//ファイル入出力
	float x_buffer;//表示位置計算用バッファ

	std::vector<std::wstring> wide_character;//文字列を一文字として保存する用
	std::vector<std::vector<std::string>> character;//文字列を一文字として保存する用
	std::string string_data;

	std::vector<int>alpha;
	std::vector<int>char_byte;

	VECTOR master_position;//文字の基本位置


	float next_speed = 40;//文字送りの速度
	int end_flag = 0;//描画が終わったのかのフラグ
	bool complete = false;//既読済みかどうか(trueで既読)


	int font_handle;

	unsigned int color = GetColor(255, 255, 255);//文字の色
	char font_name[32];
	int size;
	int thick;

	//int string_width;//文字列の長さ(可変)
	//int string_height;//文字列の高さ(可変)

	int _width;//標示幅の値の保存用

	std::string scene_number;

public:
	int CreateFontData(int Size, int Thick, int FontType, const char* FontName = NULL);//DXLIBを参照
	int GetHandle();
	float GetDrawSpeed();

	void LoadFile(const char* str = "");//テキストデータのファイルパスを指定しそのデータから描画用データを作成。(二重配列として出力。DrawFile()で描画)
	void Create(std::string str);//テキストから描画用データの作成。
	void CreateDXLIB(std::string str, int char_code);//テキストから描画用データの作成。(DXLIB使用版。char_codeにはDXLIBの文字コードのマクロを使用すること。)
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);
	void Init(float x, float y, FONT_INFO font_info);//フォントハンドルから状態を取得できないのでその回避用

	FONT_INFO GetFontInfo();

	void SetWidth(int width);//描画する最大の文字列の横幅を指定
	void ChangeFont(int handle);
	void Reset();//文字配列の中を削除し、再び文字送り描画をします。
	int GetEnd();//文字列の描画が終わったかのステータスを取得します。(1で描画終了、0で描画中)
	std::string GetSceneName();
	void SetSceneName(std::string name);

	void AllIn();//全ての文字を表示します。(読み込んだ文字列を全て表示用配列にコピーします。)
	bool GetCompleteFlag();//既読かどうかのフラグを得ます。
	void SetCompleteFlag(bool new_flag);


	//void SetLineSpaceing(int space);
	void SetSpeed(float speed);//文字送りの速度を設定します。
	void SetColor(unsigned int new_color);//新しく文字の色を設定します。

	void DrawFile(int line = 0, float frame_time = 1.0f);//LoadFile関数で読み込んだ文字列を表示する。(lineにはファイル内の表示したい行数を指定)
	void Draw(float frame_time = 1.0f);//Load関数で読み込んだ文字列を表示する。

	//void Draw(int width, float frame_time = 1.0f);//Load関数で読み込んだ文字列を表示する。(表示幅指定版)

	void Clear();	
	
	int GetSize();//文字列の大きさ(長さ)
};