#include "se_mute.h"

SEMute::SEMute()
{
	SEMute::init();
}

void SEMute::init()
{
	se_mute.Init();
}

void SEMute::LoadGraphics()
{
	se_mute.Load("pack/UI/option/se_mute.png");
}

int SEMute::DrawSEMuteButton(int x, int y, bool wire)
{
	return se_mute.BoxUI_Button_Switch(x, y, 1.0f, 1.0f, 1, wire);
}