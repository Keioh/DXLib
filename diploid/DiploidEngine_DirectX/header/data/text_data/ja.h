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
	DiploidEngineFile file;

	//DiploidEngineSetting setting;

	DiploidStringV2 font;
	DiploidStringV2 base_data;

	std::string data;

	float x_scale = 0.225f;
	float y_scale = 22 * 6;//暫定：文字サイズ*行数

	int file_handle;
	//char string_data[512];

	int string_data_line = STRING_DATA_LINE;//読み込みデータの総行数
	//int string_size = 10;


	int font_handle;

public:	
	DiploidStringV2 string[STRING_DATA_LINE];

	void Load();
	void Init(DiploidEngineSetting& setting);

	void SetSpeed(int new_speed);
	void Reset();

	int size();//読み込みデータの総行数
};