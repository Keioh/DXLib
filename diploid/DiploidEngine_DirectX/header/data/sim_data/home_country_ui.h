#pragma once
#include "DxLib.h"
#include "ver2.0/Main/Collision.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "data/sim_data/military_ui.h"


class CommandUI
{
private:

	int mouse_x, mouse_y;//マウス位置
	bool is_hit_mouse;//boxと当たっているかのフラグ
	bool is_click_mouse;//boxと当たっているときにクリックしているかのフラグ

	bool collision_active_flag = true;//当たり判定を行うかどうかのフラグ(treuで行う)

	float on_hit_color_scale = 0.8f;//boxとマウスが当たっていないときの色の暗さ(1.0fで100%)

	int bright_red = 255, bright_green = 255, bright_blue = 255;//画像の輝度の数値


	MilitaryUI military_ui;

	DiploidImageV2 military_graphics;//軍事コマンドの画像
	DiploidImageV2 production_graphics;//生産コマンドの画像
	DiploidImageV2 construction_graphics;//建設コマンドの画像
	DiploidImageV2 politics_graphics;//政治コマンドの画像


	DiploidSelectedUIV2 military;//軍事コマンド
	DiploidSelectedUIV2 production;//生産コマンド
	DiploidSelectedUIV2 construction;//建設コマンド
	DiploidSelectedUIV2 politics;//政治コマンド

public:
	void Load();
	void Init(VECTOR pos, float scale = 0.2f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	void SetCollisionActiveFlag(bool flag);
	void ResetFlag();

	bool GetCollisionActiveFlag();

	bool GetHit();
};