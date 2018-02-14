#include "apply.h"

Apply::Apply()
{
	Apply::init();
}

void Apply::init()
{
	apply.Init();
}

void Apply::LoadGraphics()
{
	apply.Load("pack/UI/option/apply.png");
}

int Apply::DrawApplyButton(int x, int y, bool wire)
{

	return apply.BoxUI_Button(x, y, 1, wire);
}