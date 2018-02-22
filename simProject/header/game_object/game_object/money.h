#pragma once
#include "DxLib.h"

class Money
{
private:

public:
	int money;

	void Init();
	void Draw(int pos_x, int pos_y, bool wire);
};