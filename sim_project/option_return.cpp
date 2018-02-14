#include "option_return.h"

OptionReturn::OptionReturn()
{
	OptionReturn::init();
}

void OptionReturn::init()
{
	option_return.Init();
}

void OptionReturn::LoadGraphics()
{
	option_return.Load("pack/UI/option/option_return.png");
}

int OptionReturn::DrawOtpionReturnButton(int x, int y, bool wire)
{
	return option_return.BoxUI_Button(x, y, 1, wire);
}