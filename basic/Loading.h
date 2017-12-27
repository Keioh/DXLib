#pragma once
#include "DxLib.h"
#include "Object_Base.h"


class Loading : public ObjectBase
{
private:
	int loading_graphics, loading_point_graphics;


public:
	int timer;

	void inti();

	void LoadGraphics();
	void DrawLoading(int x, int y);

};