#pragma once
#include <list>
#include <memory>
#include <unordered_map>
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"
#include "diploidObject\DiploidEngineObject.h"
#include "system\DiploidEngineMath.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"

#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "ver2.0/Main/Collision.h"
#include "ver2.0/Main/Camera.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "diploidObject\DiploidCreator.h"

#include "diploidStandalone\standalone.h"


#include "ver2.0/Objects/LogoScene.h"
#include "ver2.0/Objects/TitleScene.h"


using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidScreenGraphics scr_gra;

	LogoScene logo_scene;
	TitleScene title_scene;


public:
	void FileCreate();
	void Load();
	void Init();
	void Updata();
	void Draw();
	void Destory();
	void End();
};