#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"
#include "diploidImpact\DiploidEngineImpact.h"
#include "diploidLayer\DiploidEngineLayer.h"
#include "diploidObject\DiploidEngineObject.h"
#include "diploidObject\DiploidEngineTag.h"


class LawButton : public DiploidObject
{
private:

	void SelectLawButton(DiploidEngineImpact& impact, DiploidEngineLayer& layer);//�Ώۂ�I���������̏���

	void BoxAndTopImageUpdata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//�Ώۂ�I�����鏈��

	void InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//�C���v�b�g�P�̂ł̏���

public:
	void LoadTexter(const char* path);
	void LoadSound(const char* path);

	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);

	void Draw();

};