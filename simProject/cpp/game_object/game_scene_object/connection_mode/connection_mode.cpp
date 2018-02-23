#include "connection_mode.h"

void ConnectionMode::Init()
{
	key.init();
}

void ConnectionMode::Load()
{
	back_wall_graphics = LoadGraph("pack/GameObject/GameUI/connection/back_wall.png");
}

void ConnectionMode::Draw(int pos_x, int pos_y, bool wire)
{
	key.GetKeyFrame();

	//Cキーを押したらコネクションモードを切り替える。
	if (key.KeyCilick(KEY_INPUT_C) == true)
	{
		connection_mode_flag *= -1;
	}

	//コネクションモード中に行う処理
	if (connection_mode_flag == 1)
	{
		DrawGraph(pos_x, pos_y, back_wall_graphics, TRUE);
	}
}