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
	void SelectRegion(DiploidEngineImpact& impact, DiploidEngineLayer& layer);//�Ώۂ�I���������̏���

	void BoxAndBotImageUpdata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//�Ώۂ�I�����鏈��

	void InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//�C���v�b�g�P�̂ł̏���

public:
	RegionLule region_lule;

	void SetObjectNumber(int object_number);
	void SetLayerNumber(int layer_number);
	void LoadTexter(const char* path);
	void LoadSound(const char* path);
	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);
	void Draw();

	DiploidImage GetImage();//image����Ԃ��܂��B
	DiploidBox GetBox();//Box����Ԃ��܂��B
	DiploidCircle GetCircle();//Circle����Ԃ��܂��B

};