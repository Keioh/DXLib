#pragma once
#include "DxLib.h"

class FadeOut
{
private:
	int black_screen_graphics;//�摜�n���h��

	int graphics_alph;//�摜�̃��l

public:
	FadeOut();

	bool flag;

	void init();
	void LoadGraphics();

	bool DrawFadeOut(int x, int y, float speed);

};