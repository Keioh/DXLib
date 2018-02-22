#pragma once
#include "DxLib.h"

class InfomationBar
{
private:
	int back_wall_graphics;

public:
	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire = false);
};