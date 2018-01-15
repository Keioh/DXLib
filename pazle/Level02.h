#pragma once
#include "switchObject.h"

class Level02
{
private:


public:

	SwitchObject object[7];

	void init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);

};