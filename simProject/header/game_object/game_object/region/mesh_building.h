#pragma once
#include "FileInput.h"
#include "button_ui.h"
#include "building.h"
#include "game_window.h"
#include "struct_set.h"

class MeshBuilding
{
private:
	InGameWindow window;
	int window_flag = -1;//ウィンドウを表示するかしないかのフラグ
	int lock_graphics;

	void DrawStirngUI(int window_x, int window_y, Filer config);

public:
	ButtonUI market_place_button, laboratory_button, empty_lot_button;
	Building building0, building1, building2;//0=更地オブジェクト、1=交易所オブジェクト、2=研究所オブジェクト

	int building0_money, building1_money, building2_money;//建設にかかるお金
	int building0_time, building1_time, building2_time;//建設にかかる時間

	int affiliation_faction = 0;//所属しているファクション(0で無所属)
	int building_type = 0;//建物の種類(0=更地、1=交易所、2=研究所)

	void Init();
	void Load();
	void Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos);
	void Updata();
	void Draw(MODE mode, bool wire = false);
	void DrawUI(int window_x, int window_y, MODE mode, Filer config, bool wire = false);
	void ColliderOff();
	void ColliderOn();
};