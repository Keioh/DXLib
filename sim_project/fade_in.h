#pragma once
#include "DxLib.h"

class FadeIn
{
private:
	int black_screen_graphics;//�摜�n���h��

	int graphics_alph;//�摜�̃��l

public:
	FadeIn();

	bool flag;

	void init();
	void LoadGraphics();

	bool DrawFadeIn(int x, int y, float speed);

};