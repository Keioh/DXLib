#pragma once
#include <vector>
#include <string>

#include "diploidInput\DiploidEnigneFile.h"

#include "ver2.0/Graphics/DiploidStringV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"

#include "system\DiploidEngineSetting.h"

#define STRING_DATA_LINE 3

class ja_text
{
private:
	DiploidEngineFile file_string_data;
	DiploidEngineFile file_scene_data;

	DiploidTranslate trans;

	//DiploidEngineSetting setting;

	DiploidStringV2 font;
	DiploidStringV2 base_data;

	std::string data;
	std::vector<std::string> string_data;//会話データ(文字列分割前)
	std::vector<std::string> scene_name_data;//会話データとシーンの紐づけデータ(文字列分割前)

	std::vector<std::string> scene_name;//会話データとシーンの紐づけデータ(文字列分割後シーンの名前)
	std::vector<int> scene_number;//会話データとシーンの紐づけデータ(文字列分割後、画像を変更する会話データの番号)


	float x_scale = 0.225f;
	float y_scale = 22 * 6;//暫定：文字サイズ*行数

	int file_handle;
	//char string_data[512];

	int string_data_line = STRING_DATA_LINE;//読み込みデータの総行数
	//int string_size = 10;

	int line_count;//総行数

	int font_handle;

public:	
	//DiploidStringV2 string[STRING_DATA_LINE];
	std::vector<DiploidStringV2> string;//文字列データ保存、参照用
	std::vector<DiploidStringV2> name;//文字列データに対するキャラの名前の保存、参照用

	void OnceLoad();
	void Create();
	void StringInit(DiploidEngineSetting& setting);
	void NameInit(DiploidEngineSetting& setting);

	void SetSpeed(int new_speed);
	void Reset();

	int size();//読み込みデータの総行数
};