#pragma once
#include "button_ui3D.h"

class Building
{
private:
	int mouse_x, mouse_y;

public:
	ButtonUI3D bulidng_object;

	void Init();
	void Load();
	void Draw(bool wire = false);
	void Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos);
};