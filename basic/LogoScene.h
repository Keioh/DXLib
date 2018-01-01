#pragma once
#include "DxLib.h"
#include "logo.h"
#include "fade_in.h"
#include "fade_out.h"

class LogoScene
{
private:
	Logo logo;//ÉçÉSï\é¶ä÷òA
	FadeIn fade_in;
	FadeOut fade_out;

public:
	int logo_scene_flag;

	int logo_sound_handl;

	void init();

	void LoadGraphics();
	void DrawLogoScene(int x, int y);

};