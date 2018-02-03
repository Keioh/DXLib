#include "return.h"

ReturnButton::ReturnButton()
{
	ReturnButton::init();
}

void ReturnButton::init()
{
	return_button.Init();
}

void ReturnButton::LoadGraphics()
{
	return_button.Load("pack/UI/Load/retrun.png");
}

int ReturnButton::DrawReturnButton(int x, int y, bool wire)
{
	return return_button.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
}