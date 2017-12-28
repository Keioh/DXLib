#include "LoadScene.h"

void LoadScene::LoadGraphics()
{

}

void LoadScene::Init()
{
	load_scene_flag = 0;
}

void LoadScene::DrawLoadScene(int window_x, int window_y, bool wire)
{
	while (load_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawString(0, 0, "LoadScene", GetColor(0, 0, 0));
	}
}