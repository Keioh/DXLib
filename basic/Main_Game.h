#pragma once
#include "System.h"
#include "define.h"
#include "LogoScene.h"
#include "LoadingScene.h"

typedef class Main_Game
{
private:

public:
	~Main_Game(){};

	bool wire_flag;

	System main_system;

	LogoScene Logo_scene;
	LoadingScene Loading_scene;

	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();

}M_GAME;