#pragma once
#include "DxLib.h"
#include "FileInput.h"
#include "Camera3D.h"

#include "faction_information.h"

#include "character_selection.h"

#include "fade_in.h"
#include "fade_out.h"

class GameScene
{
private:
	Camera3D camera;
	CharacterSelection CS;

	FactionInformation faction_tab;

	int box3D;

public:
	GameScene();

	int game_scene_flag;	

	FadeIn fade_in;
	FadeOut fade_out;

	void Init();
	void Load();

	void DrawGameScene(int window_x, int window_y, Filer config, bool wire);

};