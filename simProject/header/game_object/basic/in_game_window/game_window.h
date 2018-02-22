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
	bool Draw(int pos_x, int pos_y, bool wire = false);//window�̑傫���̓��[�h�����摜�̑傫���Ɉˑ�(�߂�l�̓N���[�Y�{�^���������ꂽ(true)��������Ă��Ȃ�(false))
};