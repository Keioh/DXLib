#pragma once
#include "DxLib.h"

class FadeIn
{
private:
	int black_screen_graphics;//‰æ‘œƒnƒ“ƒhƒ‹

	int graphics_alph;//‰æ‘œ‚Ìƒ¿’l

public:
	FadeIn();

	bool flag;

	void init();
	void LoadGraphics();

	bool DrawFadeIn(int x, int y, float speed);

};