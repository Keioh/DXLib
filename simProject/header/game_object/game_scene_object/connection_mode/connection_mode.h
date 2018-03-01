#pragma once
#include "DxLib.h"
#include "Input.h"
#include "FileInput.h"

class ConnectionMode
{
private:
	int back_wall_graphics;

	Input key;

public:
	int connection_mode_flag = -1;

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire = false);
};