#pragma once
//#include "DxLib.h"
#include "diploidImpact\DiploidEngineImpact.h"
#include "diploidLayer\DiploidEngineLayer.h"
#include "diploidObject\DiploidEngineObject.h"

class Region : public DiploidObject
{
private:
	void BoxAndImageUpdata(DiploidEngineImpact& impact, DiploidEngineLayer& layer);

public:

	void SetObjectNumber(int object_number);
	void SetLayerNumber(int layer_number);
	void LoadTexter(const char* path);
	void LoadSound(const char* path);
	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer);
	void Draw();

	DiploidImage GetImage();//image情報を返します。
	DiploidBox GetBox();//Box情報を返します。
	DiploidCircle GetCircle();//Circle情報を返します。

};