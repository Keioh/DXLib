#pragma once
#include "System.h"
#include "define.h"
#include "FileInput.h"

#include "Collision.h"

#include "button_ui.h"


typedef class Main_Game
{
private:

public:
	Main_Game();
	~Main_Game(){};

	System main_system;

	Collision test;//コライダーテスト用

	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();

}M_GAME;