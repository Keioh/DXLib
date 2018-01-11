#pragma once
#include "DxLib.h"

class FadeOut
{
private:
	int black_screen_graphics;//‰æ‘œƒnƒ“ƒhƒ‹

	int graphics_alph;//‰æ‘œ‚Ìƒ¿’l

public:
	FadeOut();

	bool flag;

	void init();
	void LoadGraphics();

	bool DrawFadeOut(int x, int y, float speed);

};