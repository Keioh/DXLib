#pragma once
#include "Collision.h"
#include "button_ui.h"
#include "Input.h"
#include "FileInput.h"
#include "game_window.h"
#include "game_window_cursor.h"

class FactionInformation
{
private:
	Input Key;

	GameWindowCursor branch_point_window;
	GameWindowCursor laboratory_window;
	GameWindowCursor money_window;
	GameWindowCursor research_window;
	GameWindowCursor study_window;
	GameWindowCursor characteristic_window;
	GameWindowCursor block_window;

	GameWindowCursor seasons_window;
	GameWindowCursor small_seasons_window;
	GameWindowCursor years_window;
	GameWindowCursor hostility_window;
	GameWindowCursor friendship_window;
	GameWindowCursor alliance_window;
	GameWindowCursor transaction_window;

	int infomation_tab_active_flag = -1;

public:


	ButtonUI faction_box;

	InGameWindow faction_tab;

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);
	void Instructions(int pos_x, int pos_y, Filer config, bool wire);

	void FactionInfomationTabOff();//タブをオフにする。
	void CollisionOff();//ヒットボックスをオフにする。
	void CollisionOn();//ヒットボックスをオンにする。

};