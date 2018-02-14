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
	void Transform(VECTOR scale, float rotate_x, float rotate_y, float rotate_z, VECTOR trans);//3Dƒ‚ƒfƒ‹‚Ì•`ŽÊ
	void ColliderOff();
	void ColliderOn();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);
};