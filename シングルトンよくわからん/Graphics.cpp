#include "Graphics.h"

Graphics* Graphics::GetInstans()
{
	static Graphics graphics;
	return &graphics;
}

void Graphics::Load()
{
	testLoad.Load("pack\GameObject\green.png");
}

void Graphics::SetPos(float x, float y)
{
	DrawGraphF(x, y, testLoad.graphics_handl, TRUE);
}