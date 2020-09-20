#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"

class SwitchButtonBoxV2
{
private:
	DiploidBoxV2 box;//当たり判定用BOX
	DiploidCollision collision;//当たり判定

	DiploidEngineInput input;//インプット

	bool button_hit_flag = false;//ボタンに触れていればtrue
	bool button_click_flag = false;//ボタンをクリックした瞬間にtrue
	int button_selected_flag = -1;//ボタンが押されていれば1（スイッチボタンで使用）

	int mouse_button_type = MOUSE_INPUT_LEFT;//マウスのどのボタンを押せばクリック判定が有効なのか。

public:
	void Init(VECTOR pos, VECTOR size, int mouse_button);
	void Update();
	void Draw(bool draw = true);

	bool GetHit();
	bool GetClick();
	int GetSelected();

	DiploidBoxV2& GetBoxPtr();//当たり判定で用いているBOXをいじるための参照
};