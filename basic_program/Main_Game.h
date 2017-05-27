#pragma once
#include "define.h"
#include "FileInput.h"

typedef class Main_Game
{
private:

	Filer main_filer;

public:
	Main_Game();
	~Main_Game(){};

	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();
}M_GAME;