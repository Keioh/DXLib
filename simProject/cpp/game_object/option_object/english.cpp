#include "english.h"

English::English()
{
	English::init();
}

void English::init()
{
	english.Init();
}

void English::LoadGraphics()
{
	english.Load("pack/UI/option/english.png");
}

int English::DrawEnglishButton(int x, int y, bool wire)
{
	return english.BoxUI_Button_Switch(x, y, 1.0f, 1.0f, 1, wire);
}