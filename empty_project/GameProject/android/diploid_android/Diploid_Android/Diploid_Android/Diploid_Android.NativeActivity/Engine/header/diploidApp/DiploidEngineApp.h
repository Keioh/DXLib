//中枢です。
#pragma once
#include <string>
#include <list>
#include <memory>
#include <unordered_map>
#include "DxLib.h"//Dxlib本体
#include "diploidApp\DiploidEngineMain.h"//心臓部分(必ず呼ぶ)
#include "diploidObject\DiploidEngineObject.h"//円や四角や画像や音など、オブジェクト全般
#include "system\DiploidEngineMath.h"//数学式関連(DxLibもしくはC++標準もしくはその他の数学ライブラリの使用を推奨)
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"//一回だけデータを読み込むための処理群

#include "ver2.0/Graphics/DiploidCircleV2.h"//Ver2.0の円クラス
#include "ver2.0/Main/Collision.h"//Ver2.0の当たり判定処理
#include "ver2.0/Main/Camera.h"//Ver2.0の2Dにおけるカメラ処理
#include "ver2.0/Graphics/DiploidImageV2.h"//Ver2.0における画像クラス
#include "ver2.0/Graphics/DiploidBoxV2.h"//Ver2.0における四角クラス

#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidTouchUI.h"

#include "diploidScreen/DiploidEngineAndroidScreen.h"//Androidデバイスの画面情報取得クラス


//スタンドアローン関連
#include "diploidStandalone\standalone.h"//未実装

//ゲームデータ関連
//#include "diploidGraphics/diploidEffect.h"

using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:	
	DiploidEngineAndroidScreen android_screen;//Androidデバイスの画面情報
	DiploidEngineInput input;//入力関連の使用。


public:
	void FileCreate();//ゲーム起動時に一度だけファイルを作る処理。
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。	
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理
	void Destory();//削除する処理。
	void End();//engine終了前処理。
};