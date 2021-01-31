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

	DiploidEngineSetting setting;

	DiploidStrings font;
	DiploidStrings data[256];

	float x_scale = 0.2f;
	float y_scale = 0.8f;

	int file_handle;
	char string_data[512];

public:
	void Load();
	void SetSpeed(int new_speed);

	std::vector<DiploidStrings> string;
};