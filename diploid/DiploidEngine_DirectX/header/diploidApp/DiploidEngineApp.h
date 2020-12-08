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

#include "diploidStandalone\standalone.h"


using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidSoftImage soft_date;
	float test = 0.f;

public:
	void FileCreate();
	void Load();
	void Init();
	void Updata();
	void Draw();
	void Destory();
	void End();
};