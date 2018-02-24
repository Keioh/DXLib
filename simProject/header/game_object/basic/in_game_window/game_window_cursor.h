#pragma once
#include "DxLib.h"
#include "Collision.h"

class GameWindowCursor
{
private:
	Collision hit_box;

public:

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire = false);
};