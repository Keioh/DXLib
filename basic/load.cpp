#include "load.h"

void Load::init()
{
	load.Init();
}

void Load::LoadGraphics()
{
	load.Load("pack/UI/Title/load.png");
}

int Load::DrawLoadButton(int x, int y, bool wire)
{
	return load.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
}