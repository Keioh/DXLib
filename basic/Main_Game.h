#pragma once

//システム関連
#include "System.h"
#include "define.h"

//シーン関連
#include "LogoScene.h"
#include "LoadingScene.h"
#include "StartScene.h"
#include "GameScene.h"
#include "OptionScene.h"
#include "LoadScene.h"


typedef class Main_Game
{
private:

public:
	~Main_Game(){};

	bool wire_flag;

	//システム関連
	System main_system;

	//シーン関連
	LoadingScene Loading_scene;
	LogoScene Logo_scene;
	StartScene Start_scene;
	GameScene Game_scene;
	OptionScene Option_scene;
	LoadScene Load_scene;

	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();

}M_GAME;