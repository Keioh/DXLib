#pragma once
#include "diploidObject\DiploidEngineTag.h"
#include "region\region.h"

class World
{
private:

public:
	Region region_01;

	void Load();//‚·‚×‚Ä‚ğ“Ç‚İ‚Ş
	void Init(VECTOR position);//•K‚¸“Ç‚İ‚¾‚·

	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer);

	//DiploidImage GetImage();//imageî•ñ‚ğ•Ô‚µ‚Ü‚·B

};