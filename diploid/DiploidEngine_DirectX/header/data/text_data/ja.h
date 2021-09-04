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
	DiploidTranslate trans;

	//DiploidEngineSetting setting;

	DiploidStringV2 font;
	DiploidStringV2 base_data;

	std::string data;
	std::vector<std::string> string_data;

	float x_scale = 0.225f;
	float y_scale = 22 * 6;//�b��F�����T�C�Y*�s��

	int file_handle;
	//char string_data[512];

	int string_data_line = STRING_DATA_LINE;//�ǂݍ��݃f�[�^�̑��s��
	//int string_size = 10;

	int line_count;//���s��

	int font_handle;

public:	
	//DiploidStringV2 string[STRING_DATA_LINE];
	std::vector<DiploidStringV2> string;//������f�[�^�ۑ��A�Q�Ɨp
	std::vector<DiploidStringV2> name;//������f�[�^�ɑ΂���L�����̖��O�̕ۑ��A�Q�Ɨp

	void OnceLoad();
	void Create();
	void StringInit(DiploidEngineSetting& setting);
	void NameInit(DiploidEngineSetting& setting);

	void SetSpeed(int new_speed);
	void Reset();

	int size();//�ǂݍ��݃f�[�^�̑��s��
};