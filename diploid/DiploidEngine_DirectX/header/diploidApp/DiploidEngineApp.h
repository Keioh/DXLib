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
#include "system/define.h"

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
#include "ver2.0/Objects/GameScene.h"
#include "ver2.0/Objects/OptionScene.h"

using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	LogoScene logo_scene;
	TitleScene title_scene;
	GameScene game_scene;
	OptionScene option_scene;

public:
	void FileCreate(DiploidEngineApp* app);
	void Load(DiploidEngineApp* app);//一回だけ読み込む
	void Init(DiploidEngineApp* app);//一回だけ初期化
	void Updata(DiploidEngineApp* app);//ループ処理(fps依存)
	void Draw(DiploidEngineApp* app);//描画
	void Destory(DiploidEngineApp* app);//ver1.0の機能でのオブジェクト削除
	void End(DiploidEngineApp* app);//ゲーム終了時の処理
};