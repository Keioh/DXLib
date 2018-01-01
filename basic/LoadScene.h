#pragma once
#include "DxLib.h"

#include "fade_in.h"
#include "fade_out.h"

#include "return.h"

class LoadScene
{
private:

	ReturnButton return_button;

	FadeIn fade_in;
	FadeOut fade_out;

public:
	LoadScene();


	bool flag;

	int load_scene_flag;

	void LoadGraphics();
	void Init();

	void DrawLoadScene(int window_x, int window_y, bool wire);

};