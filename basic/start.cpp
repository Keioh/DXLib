#include "start.h"

Start::Start()
{
	Start::init();
}

void Start::init()
{
	start.Init();
}

void Start::LoadGraphics()
{
	start.Load("pack/UI/Title/new_game.png");
}

int Start::DrawStartButton(int x, int y, bool wire)
{
	return start.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
}