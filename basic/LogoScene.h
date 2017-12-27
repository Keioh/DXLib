#pragma once
#include "DxLib.h"
#include "logo.h"

class LogoScene
{
private:
	Logo logo;//ロゴ表示関連

public:
	int logo_scene_flag;

	int logo_sound_handl;

	void init();

	void LoadGraphics();
	void DrawLogoScene(int x, int y);

};