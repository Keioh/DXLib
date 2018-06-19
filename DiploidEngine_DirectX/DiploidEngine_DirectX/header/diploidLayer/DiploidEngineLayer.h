//オブジェクトを描写する順番を決めるためのレイヤーシステム

#pragma once
#include <vector>
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidEngineLayer
{
private:
	std::vector<DiploidImage> image_top_vector;

public:

	void PushTopGraphics(DiploidImage image);
	void Updata();
	void Draw(bool draw = true);
};