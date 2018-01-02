#pragma once
#include "DxLib.h"
#include "Loading.h"

class LoadingScene
{
private:
	Loading loading;

public:
	LoadingScene();

	int loading_scene_flag;

	void Init();
	void Load();

	void DrawLoadingScene(int x, int y);

};