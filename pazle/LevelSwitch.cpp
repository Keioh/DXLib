#include "LevelSwitch.h"

void LevelSwitch::Load()
{
	fade_in.LoadGraphics();

	level_reset_switch.Load("");

	level01_switch.Load("pack/GameObject/number/01.png");
	level02_switch.Load("pack/GameObject/number/02.png");
	level03_switch.Load("pack/GameObject/number/03.png");

}

void LevelSwitch::init()
{
	fade_in.init();

	//オブジェクトのα値を0で初期化
	anime_alph = 0;

	//レベル選択画面にフラグを立てる
	select_level = 0;

	//色をランダム取得
	level_reset_switch.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
	level01_switch.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
	level02_switch.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
	level03_switch.color = GetColor(GetRand(255), GetRand(255), GetRand(255));

	//初期化
	level_reset_switch.Init();
	level01_switch.Init();
	level02_switch.Init();
	level03_switch.Init();

}

void LevelSwitch::AnimtionInit()
{
	//オブジェクトのα値を0で初期化
	anime_alph = 0;
	anime_sin = 0.0f;
}

void LevelSwitch::Draw(int pos_x, int pos_y, bool wire)
{
	anime_alph += 20;
	anime_sin += 0.05f;

	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);

	if (level01_switch.CircleUI_Button(pos_x + 32, pos_y + 32, 18, 1, wire) == true)
	{
		select_level = 1;
	}
	
	if (level02_switch.CircleUI_Button(pos_x + 32 * 2 + 10, pos_y + 32, 18, 1, wire) == true)
	{
		select_level = 2;
	}

	if (level03_switch.CircleUI_Button(pos_x + 32 * 3 + 20, pos_y + 32, 18, 1, wire) == true)
	{
		select_level = 3;
	}	

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void LevelSwitch::ResetButtonDraw(int pos_x, int pos_y, bool wire)
{
	if (level_reset_switch.BoxUI_Button_BOX(pos_x, pos_y, 100, 100, 1, wire) == true)
	{
		LevelSwitch::AnimtionInit();
		select_level = 0;
	}
}