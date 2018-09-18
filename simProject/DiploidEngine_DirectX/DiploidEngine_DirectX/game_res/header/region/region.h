#pragma once
//#include "DxLib.h"
#include "lule\region_lule.h"
#include "diploidObject\DiploidEngineTag.h"
#include "diploidImpact\DiploidEngineImpact.h"
#include "diploidLayer\DiploidEngineLayer.h"
#include "diploidObject\DiploidEngineObject.h"

class Region : public DiploidObject
{
private:
	void SelectRegion(DiploidEngineImpact& impact, DiploidEngineLayer& layer);//対象を選択した時の処理

	void BoxAndBotImageUpdata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//対象を選択する処理

	void InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//インプット単体での処理

public:
	RegionLule region_lule;

	void SetObjectNumber(int object_number);
	void SetLayerNumber(int layer_number);
	void LoadTexter(const char* path);
	void LoadSound(const char* path);
	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);
	void Draw();

	DiploidImage GetImage();//image情報を返します。
	DiploidBox GetBox();//Box情報を返します。
	DiploidCircle GetCircle();//Circle情報を返します。

};