#pragma one
#include <vector>
#include "ver2.0/Graphics/DiploidStrings.h"
#include "system\DiploidEngineSetting.h"

class ja_text
{
private:
	DiploidEngineSetting setting;

	DiploidStrings font;
	DiploidStrings data[256];

public:
	void Load();

	std::vector<DiploidStrings> string;
};