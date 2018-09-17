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

	void SelectLawButton(DiploidEngineImpact& impact, DiploidEngineLayer& layer);//対象を選択した時の処理

	void BoxAndTopImageUpdata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//対象を選択する処理

	void InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);//インプット単体での処理

public:
	void LoadTexter(const char* path);
	void LoadSound(const char* path);

	void Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input);

	void Draw();

};