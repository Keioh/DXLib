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


	bool press_click_mouse;
	bool release_click_mouse;

	int press_time_mouse = 0;
	int release_time_mouse = 0;

	int press_time = 0;//押している時間
	int release_time = 0;//離している時間

	//タッチ関連
	int touch_position_x;//タッチしているX座標
	int touch_position_y;//タッチしているY座標
	int touch_id;//タッチID
	int touch_device_id;//デバイスID

	int touch_size;//タッチしている数

	int touch_release_flag;


public:	

	//現在のマウス座標
	int mouse_pos_adr_x;
	int mouse_pos_adr_y;

	//マウスホイールの回転関係
	float mouse_whell_volume = 0;
	float mouse_whell_scale = 1.0f;

	char Key[256];

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
	int GetWhellVolume();//マウスホイールの回転数を瞬間的に取得します。
	float GetWhellVolume_Scale(float max = 5.0f, float min = 0.2f, float scale = 0.1f);//マウスホイールの回転数を元にスケール値を取得します。(初期値は1.0f、maxにはスケール最大値を指定、minには最小値を指定, scaleには回転数の倍率を指定)

	VECTOR GetMousePressPosition();//押した瞬間のマウス座標の取得。
	VECTOR GetMouseReleasePosition();//離した瞬間のマウス座標の取得。
	VECTOR GetMousePosition();//現在のマウス座標の取得。

	bool GetTouch();//タッチしている間、trueが返る。
	bool GetReleaseTouch();//指が離された瞬間の判定。(離した瞬間にtrueが返る。)
	int GetTouchPositionX();//タッチされた瞬間のX座標
	int GetTouchPositionY();//タッチされた瞬間のY座標

	int GetTouchReleaseFlag();
};