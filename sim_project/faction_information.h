#pragma once
#include "Collision.h"
#include "button_ui.h"
#include "Input.h"
#include "FileInput.h"
#include "game_window.h"

class FactionInformation
{
private:
	Input Key;

	int infomation_tab_active_flag = -1;

	void DrawFactionStrings(int pos_x, int pos_y, Filer config);

public:
	Collision branch_point_collision;//支拠点の説明
	Collision laboratory_collision;//研究所の説明

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