#pragma once
#include "define.h"
#include "3DSystem.h"
#include "FileInput.h"
#include "Net.h"
#include "Sound.h"
#include "Dice.h"

typedef class Main_Game
{
private:
	int back_screen;

	Filer main_filer;
	NET_GAMING main_net;
	Sound main_sound;
	DICE main_dice;

public:
	Main_Game();
	~Main_Game(){};
	int mouse_x, mouse_y;
	int sound_play_flag;
	int sound_name;
	int sound_number;

	int dice_role;//ダイスロールの結果を保存
	int dice_role_custom;//ダイスロールの結果を保存

	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();
}M_GAME;