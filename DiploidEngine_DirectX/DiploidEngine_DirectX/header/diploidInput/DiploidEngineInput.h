#pragma once
#include <vector>
#include "DxLib.h"
//#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidEngineInput
{

private:

	int press_time = 0;//押している時間
	int release_time = 0;//離している時間

public:	
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
	bool GetPressKey(int DXLIB_KEY_CODE);//キーを押した瞬間の判定。(押していたらtrueが返る)
	bool GetReleaseKey(int DXLIB_KEY_CODE);//キーを離された瞬間の判定。(押していたらtrueが返る)

	bool GetMouse(int DXLIB_MOUSE_CODE);//マウスを押したか押していないかの判定。(押していたらtrueが返る)
	bool GetPressMouse(int DXLIB_MOUSE_CODE);//マウスを押した瞬間の判定。(押していたらtrueが返る)
	bool GetReleaseMouse(int DXLIB_MOUSE_CODE);//マウスを離した瞬間の判定。(押していたらtrueが返る)

};