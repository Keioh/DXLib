#include "bgm_mute.h"

BGMMute::BGMMute()
{
	BGMMute::init();
}

void BGMMute::init()
{
	bgm_mute.Init();
}

void BGMMute::LoadGraphics()
{
	bgm_mute.Load("pack/UI/option/bgm_mute.png");
}

int BGMMute::DrawBGMMuteButton(int x, int y, bool wire)
{
	return bgm_mute.BoxUI_Button_Switch(x, y, 1.0f, 1.0f, 1, wire);
}