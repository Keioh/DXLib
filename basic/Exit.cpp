#include "Exit.h"

void Exit::init()
{
	exit.Init();
}

void Exit::LoadGraphics()
{
	exit.Load("pack/UI/Title/exit.png");
}

int Exit::DrawExitButton(int x, int y, bool wire)
{
	return exit.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
}