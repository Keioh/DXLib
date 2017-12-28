#pragma once
#include "start.h"
#include "load.h"
#include "exit.h"
#include "option.h"

class StartScene
{
private:

public:
	Start start;
	Load load;
	Option option;
	Exit exit;

	int start_scene_flag;//-1でゲーム終了、0でスタート画面をループ、1でnew game、2でロード画面、3でオプション画面。

	void LoadGraphics();
	void Init();

	void DrawStartScene(int window_x, int window_y, bool wire);

};