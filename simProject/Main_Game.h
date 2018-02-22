#pragma once
#include <iostream>

//�V�X�e���֘A
#include "DxLib.h"
#include "System/System.h"
#include "define.h"
#include "input/FileInput.h"

//�V�[���֘A
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

	//�V�X�e���֘A
	System main_system;
	Filer config_data;

	//�V�[���֘A
	LoadingScene Loading_scene;
	LogoScene Logo_scene;
	StartScene Start_scene;
	GameScene Game_scene;
	LoadScene Load_scene;

	void Main_Load();
	void Main_Init();
	void Main_Game_Loop();

}M_GAME;