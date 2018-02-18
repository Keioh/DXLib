#pragma once
#include "Collision.h"
#include "button_ui.h"

class InGameWindow
{
private:
	int window_tab_edge_graphics, window_tab_back_wall_graphics;

public:
	ButtonUI infomation_tab_close;
	Collision window;

	int click;
	bool hit = false;
	int graphics_size_x, graphics_size_y;

	void Init();
	void Load(char* path);
	bool Draw(int pos_x, int pos_y, bool wire = false);//windowの大きさはロードした画像の大きさに依存(戻り値はクローズボタンが押された(true)か押されていない(false))
};