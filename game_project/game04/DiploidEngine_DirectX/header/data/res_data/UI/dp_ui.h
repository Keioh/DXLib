#pragma once
#include "DxLib.h"
#include "data/res_data/anime/animation.h"

#include "data/res_data/player/player.h"

class DpUI
{
private:

public:
	DiploidImageV2 image[10];
	Animation defense_animations[3];

	float defense;
	float anime_speed = 4.0f;

public:
	void LoadGraphics();
	void LoadGraphicsHandle();

	void Init(VECTOR pos, float scale);
	void Updata(Player player);
	void Draw(bool draw = true);

};