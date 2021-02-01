#pragma once
#include <vector>
#include <string>

#include "diploidInput\DiploidEnigneFile.h"

#include "ver2.0/Graphics/DiploidStrings.h"
#include "system\DiploidEngineSetting.h"

class ja_text
{
private:
	DiploidEngineFile file;

	//DiploidEngineSetting setting;

	DiploidStrings font;
	DiploidStrings data[256];

	float x_scale = 0.225f;
	float y_scale = 22 * 6;//暫定：文字サイズ*行数

	int file_handle;
	char string_data[512];

	int string_data_line = 256;//読み込みデータの総行数

public:
	void Load();
	void Init(DiploidEngineSetting& setting);

	void SetSpeed(int new_speed);

	std::vector<DiploidStrings> string;
};