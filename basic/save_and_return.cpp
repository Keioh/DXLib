#include "save_and_return.h"

SaveAndReturn::SaveAndReturn()
{
	SaveAndReturn::init();
}

void SaveAndReturn::init()
{
	save_and_return.Init();
}

void SaveAndReturn::LoadGraphics()
{
	save_and_return.Load("pack/UI/option/save_and_return.png");
}

int SaveAndReturn::DrawSaveAndReturnButton(int x, int y, bool wire)
{
	return save_and_return.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
}