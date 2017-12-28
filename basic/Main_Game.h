#pragma once
#include "System.h"
#include "define.h"
#include "LogoScene.h"
#include "LoadingScene.h"
#include "StartScene.h"


typedef class Main_Game
{
private:

public:
	~Main_Game(){};

	bool wire_flag;

	System main_system;

	LoadingScene Loading_scene;
	LogoScene Logo_scene;
	StartScene Start_scene;


	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();

}M_GAME;