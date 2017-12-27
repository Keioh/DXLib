#pragma once
#include "DxLib.h"
#include "logo.h"

class LogoScene
{
private:
	Logo logo;//ÉçÉSï\é¶ä÷òA

public:
	int logo_scene_flag;

	int logo_sound_handl;

	void init();

	void LoadGraphics();
	void DrawLogoScene(int x, int y);

};