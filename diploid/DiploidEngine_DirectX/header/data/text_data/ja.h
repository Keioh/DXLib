#pragma one
#include <vector>
#include "ver2.0/Graphics/DiploidStrings.h"

class ja_text
{
private:
	DiploidStrings font;
	DiploidStrings data[256];

public:
	void Load();

	std::vector<DiploidStrings> string;
};