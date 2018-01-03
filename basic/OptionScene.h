#pragma once
#include "DxLib.h"

#include "save_and_return.h"

#include "fade_in.h"
#include "fade_out.h"

#include "button_ui.h"

class OptionScene
{
private:
	SaveAndReturn save_and_return;
	bool flag;//ƒNƒŠƒbƒN”»’è•Û‘¶•Ï”

public:
	OptionScene();

	ButtonUI test;

	FadeIn fade_in;
	FadeOut fade_out;

	int option_scene_flag;

	void Load();
	void Init();

	void DrawOptionScene(int window_x, int window_y, bool wire);

};