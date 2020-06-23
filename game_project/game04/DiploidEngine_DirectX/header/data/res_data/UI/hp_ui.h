#pragma once
#include "DxLib.h"
#include "data/res_data/anime/animation.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "data/res_data/player/player.h"

class HpUI
{
private:
	DiploidImageV2 image[10];
	Animation hp_animations[3];

	float hp;
	float anime_speed = 6.0f;

public:
	void LoadGraphics();
	void LoadGraphicsHandle();

	void Init(VECTOR pos, float scale);
	void Updata(Player player);
	void Draw(bool draw = true);
};