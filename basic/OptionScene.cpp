#include "OptionScene.h"

void OptionScene::LoadGraphics()
{

}

void OptionScene::Init()
{
	option_scene_flag = 0;
}

void OptionScene::DrawOptionScene(int window_x, int window_y, bool wire)
{
	while (option_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawString(0, 0, "OptionScene", GetColor(0, 0, 0));
	}
}