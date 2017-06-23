#pragma once
#include "System.h"
#include "define.h"
#include "FileInput.h"

#include "Collision.h"

typedef class Main_Game
{
private:

	Filer main_filer;
	Collision main_collision;

public:
	Main_Game();
	~Main_Game(){};

	System main_system;

	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();

}M_GAME;