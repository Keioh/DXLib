#pragma once
#include <vector>
#include "DxLib.h"
//#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidEngineInput
{

private:
	int release_key_flag = -1;

	//押した瞬間のマウス座標
	int press_click_position_x;
	int press_click_position_y;

	//離した瞬間のマウス座標
	int release_click_position_x;
	int release_click_position_y;

	//現在のマウス座標
	int mouse_pos_adr_x;
	int mouse_pos_adr_y;


	int press_time = 0;//押している時間
	int release_time = 0;//離している時間

public:	
	char key[256];
	//char buffer[256];

	int Check_Mouse;
	int MOUSE_BUTTON = 0;
	int CLICK_X = 0;
	int CLICK_Y = 0;
	int LOG_TYPE = 0;


	void Init();
	void Update();
	void Draw(int x, int y, bool debug = false);

	bool GetKey(int DXLIB_KEY_CODE);//キーを押したか押していないかの判定。(押していたらtrueが返る)
	bool GetPressKey(int DXLIB_KEY_CODE);//キーを押した瞬間の判定。(押し瞬間にtrueが返る)
	bool GetReleaseKey(int DXLIB_KEY_CODE);//キーを離された瞬間の判定。(離した瞬間にtrueが返る)

	bool GetMouse(int DXLIB_MOUSE_CODE);//マウスを押したか押していないかの判定。(押していたらtrueが返る)
	bool GetPressMouse(int DXLIB_MOUSE_CODE);//マウスを押した瞬間の判定。(押した瞬間にtrueが返る)
	bool GetReleaseMouse(int DXLIB_MOUSE_CODE);//マウスを離した瞬間の判定。(離した瞬間にtrueが返る)

	VECTOR GetMousePressPosition();//押した瞬間のマウス座標の取得。
	VECTOR GetMouseReleasePosition();//離した瞬間のマウス座標の取得。
	VECTOR GetMousePosition();//現在のマウス座標の取得。

};