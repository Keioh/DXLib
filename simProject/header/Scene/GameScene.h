#pragma once
#include "DxLib.h"
#include "FileInput.h"
#include "fps.h"
#include "Camera3D.h"

#include "infomation_bar.h"
#include "money.h"

#include "faction_information.h"
#include "headquarters.h"
#include "research.h"
#include "study.h"
#include "diplomacy.h"
#include "game_timer.h"

#include "character_selection.h"

#include "fade_in.h"
#include "fade_out.h"

#include "Box3D.h"



class GameScene
{
private:
	FPS fps_counter;
	Camera3D camera;
	CharacterSelection CS;

	GameTimer timer;

	InfomationBar infomation_bar;
	Money money;

	Research research;
	Study study;
	Diplomacy diplomacy;

	FactionInformation faction_tab;
	Headquarters headquarters;

	Box3D terrain;

	int test_textur;

public:
	GameScene();

	int game_scene_flag;	

	FadeIn fade_in;
	FadeOut fade_out;

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, Filer config, bool wire);

};