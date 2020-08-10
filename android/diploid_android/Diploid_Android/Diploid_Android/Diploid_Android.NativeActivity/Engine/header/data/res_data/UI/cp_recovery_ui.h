#pragma once
#include "DxLib.h"
#include "data/res_data/player/player.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "data/number.h"

class CpRecoveryUI
{
private:
	DiploidImageV2 image[1];
	Number1000 number;

	float cp_recovery;

public:
	void LoadGraphics();
	void LoadGraphicsHandle();

	void Init(VECTOR pos, float scale);
	void Updata(Player player);
	void Draw(bool draw = true);
};