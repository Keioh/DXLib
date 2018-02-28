#pragma once
#include "struct_set.h"
#include "button_ui3D.h"

class Building
{
private:
	int mouse_x, mouse_y;
	int graphics_alph = 255;
	bool object_click;
	MODE flag;//ƒNƒŠƒbƒN‚µ‚½‚Æ‚«‚Ì”»’è

public:
	ButtonUI3D bulidng_object;

	void Init();
	void Load();
	void Mode(MODE mode_flag);
	void Draw(bool wire = false);
	void DrawUI();
	void Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos);
};