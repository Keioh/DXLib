#pragma once

//�V�X�e���֘A
#include "System.h"
#include "define.h"

//�V�[���֘A
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

	//�V�X�e���֘A
	System main_system;

	//�V�[���֘A
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