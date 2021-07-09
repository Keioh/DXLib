#pragma once
#include <string>
#include <vector>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "diploidInput\DiploidEnigneFile.h"


class DiploidStringV2
{
private:
	DiploidEngineFile file;//ファイル入出力
	float x_buffer;//表示位置計算用バッファ

	std::vector<std::wstring> wide_character;//文字列を一文字として保存する用
	std::vector<std::vector<std::string>> character;//文字列を一文字として保存する用
	std::string string_data;

	VECTOR master_position;//文字の基本位置


	int font_handle;

	char font_name;
	int size;
	int thick;

public:
	int CreateFontData(int Size, int Thick, int FontType, char* FontName = NULL);//DXLIBを参照
	int GetHandle();
	//float GetDrawSpeed();

	void LoadFile(const char* str = "");//テキストデータのファイルパスを指定しそのデータから描画用データを作成。(二重配列として出力。DrawFile()で描画)
	void Create(std::string str);//テキストから描画用データの作成。
	void Init(float x, float y, int new_font_handle);
	void Init(float x, float y);

	void ChangeFont(int handle);
	//void Reset();//文字配列の中を削除し、再び文字送り描画をします。
	//int GetEnd();//文字列の描画が終わったかのステータスを取得します。(1で描画終了、0で描画中)
	//std::string GetSceneName();
	//void SetSceneName(std::string name);

	//void AllIn();//全ての文字を表示します。(読み込んだ文字列を全て表示用配列にコピーします。)
	//bool GetCompleteFlag();//既読かどうかのフラグを得ます。
	//void SetCompleteFlag(bool new_flag);

	//void SetLineSpaceing(int space);
	//void SetSpeed(float speed);//文字送りの速度を設定します。
	//void SetColor(unsigned int new_color);//新しく文字の色を設定します。

	void DrawFile(int line = 0, float frame_time = 1.0f);//LoadFile関数で読み込んだ文字列を表示する。(lineにはファイル内の表示したい行数を指定)
	void Draw(float frame_time = 1.0f);//Load関数で読み込んだ文字列を表示する。(1行512文字)

	//void Draw(int width, float frame_time = 1.0f);//Load関数で読み込んだ文字列を表示する。(1行512文字)(表示幅指定版)

	void Clear();
};