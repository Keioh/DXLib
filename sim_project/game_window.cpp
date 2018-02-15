#include "game_window.h"

void InGameWindow::Init()
{
	infomation_tab_close.Init();
}

void InGameWindow::Load(char* path)
{
	infomation_tab_close.Load("pack/GameObject/GameUI/game_window/close.png");
	window_tab_edge_graphics = LoadGraph("pack/GameObject/GameUI/game_window/edge.png");
	window_tab_back_wall_graphics = LoadGraph(path);
}

bool InGameWindow::Draw(int pos_x, int pos_y, bool wire)
{
	GetGraphSize(window_tab_back_wall_graphics, &graphics_size_x, &graphics_size_y);

	DrawGraph(pos_x, pos_y, window_tab_back_wall_graphics, TRUE);//”wŒi

	click = infomation_tab_close.BoxUI_Button(pos_x + graphics_size_x - 32, pos_y, 1, wire);

	//Žl‚ÂŠp
	DrawGraph(pos_x + graphics_size_x - 64, pos_y, window_tab_edge_graphics, TRUE);
	DrawRotaGraph3(pos_x + 32, pos_y + 32, 32, 32, 1.0f, 1.0f, 0.0f * DX_PI_F / 180, window_tab_edge_graphics, TRUE, TRUE);
	DrawRotaGraph3(pos_x + 32, pos_y + graphics_size_y - 32, 32, 32, 1.0f, 1.0f, 180.0f * DX_PI_F / 180, window_tab_edge_graphics, TRUE, FALSE);
	DrawRotaGraph3(pos_x + graphics_size_x - 32, pos_y + graphics_size_y - 32, 32, 32, 1.0f, 1.0f, 180.0f * DX_PI_F / 180, window_tab_edge_graphics, TRUE, TRUE);

	if (click == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}