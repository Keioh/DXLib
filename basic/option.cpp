#include "option.h"

Option::Option()
{
	Option::init();
}

void Option::init()
{
	option.Init();
}

void Option::LoadGraphics()
{
	option.Load("pack/UI/Title/option.png");
}

int Option::DrawOptionButton(int x, int y, bool wire)
{
	return option.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
}