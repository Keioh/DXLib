#pragma once
#include <vector>
#include "ver2.0/Graphics/DiploidStrings.h"
#include "system\DiploidEngineSetting.h"

class ja_text
{
private:
	DiploidEngineSetting setting;

	DiploidStrings font;
	DiploidStrings data[256];

	float x_scale = 0.2f;
	float y_scale = 0.8f;

	//int file_handle;
	//char string_data[512];

public:
	void Load();

	std::vector<DiploidStrings> string;
};