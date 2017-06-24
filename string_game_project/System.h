#pragma once
#include "Vector3.h"

class System
{

public:
	System();
	~System(){};

	Vector3 window_size;

	void Dx_Init(bool w_mode, int r, int g, int b, char* name);

	void System_load();

	bool Black_Screen();

	bool Black_Screen_Re();

	void App_End(int key);

	void Cursor_Load();

	void Cursor_Draw(int& mouse_x, int& mouse_y);

	bool Circle_Hit(int x, int y, float r, int x2, int y2, float r2);

	bool Mouse_Cilck(int MouseInput, int flag);

	bool Mouse_Input_Click(int mouseinput);

};