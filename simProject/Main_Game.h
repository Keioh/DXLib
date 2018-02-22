#pragma once
#include <iostream>

//システム関連
#include "DxLib.h"
#include "System/System.h"
#include "define.h"
#include "input/FileInput.h"

//シーン関連
#include "Scene/LogoScene.h"
#include "Scene/LoadingScene.h"
#include "Scene/StartScene.h"
#include "Scene/GameScene.h"
#include "Scene/LoadScene.h"


typedef class Main_Game
{
private:

public:
	Main_Game();
	~Main_Game(){};

	bool wire_flag;

	//SoundSystem test;

	//システム関連
	System main_system;
	Filer config_data;

	//シーン関連
	LoadingScene Loading_scene;
	LogoScene Logo_scene;
	StartScene Start_scene;
	GameScene Game_scene;
	LoadScene Load_scene;

	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();

}M_GAME;