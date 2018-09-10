#pragma once
#include "diploidObject\DiploidEngineTag.h"
#include "region\region.h"

class World
{
private:

public:
	Region region_01;

	void Load();//すべてを読み込む
	void Init(VECTOR position);//必ず読みだす

	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer);

	//DiploidImage GetImage();//image情報を返します。

};