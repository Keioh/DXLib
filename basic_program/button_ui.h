#pragma once
#include "Object_Base.h"
#include "Collision.h"

class ButtonUI : public ObjectBase
{
private:
	Collision box_collision;
	int graphics;

public:

	ButtonUI();

	int Load(char* path);

	int BoxUI_Button(int pos_x, int pos_y, float scale_x, float scale_y, bool wire = false);//バグにつきスケールの値は1.0fで使うこと

};