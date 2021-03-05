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
#include "ver2.0/Objects/FileScene.h"

using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	LogoScene logo_scene;
	TitleScene title_scene;
	GameScene game_scene;
	OptionScene option_scene;
	FileScene file_scene;

public:
	void FileCreate(DiploidEngineApp* app);
	void OnceLoad(DiploidEngineApp* app);//一回だけ音を読み込む
	void Load(DiploidEngineApp* app);//一回だけ画像を読み込む(解像度を変更した際にも呼ばれます。)
	void OnceInit(DiploidEngineApp* app);//一回だけ音を初期化
	void Init(DiploidEngineApp* app);//一回だけ画像を初期化(解像度を変更した際にも呼ばれます。再読み込み時に値を変更したくない場合はUpdata()関数で処理をすること。)
	void Updata(DiploidEngineApp* app);//ループ処理(fps依存)
	void Draw(DiploidEngineApp* app);//描画
	void Destory(DiploidEngineApp* app);//ver1.0の機能でのオブジェクト削除
	void End(DiploidEngineApp* app);//ゲーム終了時の処理
};