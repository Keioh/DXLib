#include "japanese.h"

Japanese::Japanese()
{
	Japanese::init();
}

void Japanese::init()
{
	japanese.Init();
}

void Japanese::LoadGraphics()
{
	japanese.Load("pack/UI/option/japanese.png");
}

int Japanese::DrawJapaneseButton(int x, int y, bool wire)
{
	return japanese.BoxUI_Button_Switch(x, y, 1.0f, 1.0f, 1, wire);
}