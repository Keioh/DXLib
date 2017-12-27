#pragma once
#include "DxLib.h"
#include "Loading.h"

class LoadingScene
{
private:
	Loading loading;

public:
	int loading_scene_flag;

	void Init();
	void LoadGraphics();

	void DrawLoadingScene(int x, int y);

};