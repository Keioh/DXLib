#pragma once
#include "Input.h"
#include "button_ui.h"
#include "FileInput.h"
#include "button_ui3D.h"

class Headquarters
{
private:
	Input key;

	ButtonUI headquarters_tab_close;


public:
	ButtonUI3D headquarters_button;

	int headquarters_tab_active = -1;

	void Init();
	void Load();
	void DrawModel(VECTOR pos);//3Dƒ‚ƒfƒ‹‚Ì•`ŽÊ
	void Draw(int pos_x, int pos_y, Filer config, bool wire);
};