#pragma once
#include <map>
#include "DxLib.h"
//#include "diploidApp\DiploidEngineApp.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "system/define.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "ver2.0/Objects/DiploidNovelScene.h"
#include "diploidScreen\DiploidEngineScreen.h"

class DiploidSceneObject
{
private:
	//�摜
	std::map<std::string, DiploidImageV2> imageV2_map;

	//�A�j���[�V����
	std::map<std::string, DiploidAnimation> anime_map;

public:
	void AddObject(DiploidImageV2 object);
	void AddObject(DiploidAnimation object, std::string name);

};