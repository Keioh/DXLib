#pragma once
#include "switchObject.h"

class Level01
{
private:


public:

	SwitchObject object[4];

	void init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);

};