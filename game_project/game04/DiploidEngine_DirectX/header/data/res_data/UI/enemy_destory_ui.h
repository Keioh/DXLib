#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "data/res_data/player/player.h"
#include "data/number.h"

class EnemyDestoryUI
{
private:
	DiploidImageV2 image[2];
	Number1000 number;

	float enemy_destory_volume = 0.0f;

public:
	void LoadGraphics();
	void LoadGraphicsHandle();

	void Init(VECTOR pos, float scale);
	void Updata(Player player);
	void Draw(bool draw = true);

};