#pragma once
#include "diploidObject\DiploidEngineTag.h"
#include "region\region.h"

class World
{
private:

public:
	Region region_01;

	void Load();//���ׂĂ�ǂݍ���
	void Init(VECTOR position);//�K���ǂ݂���

	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer);

	//DiploidImage GetImage();//image����Ԃ��܂��B

};