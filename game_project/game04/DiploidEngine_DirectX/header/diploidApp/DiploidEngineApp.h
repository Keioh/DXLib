//中枢です。
#pragma once
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


//スタンドアローン関連
#include "diploidStandalone\standalone.h"//未実装

//ゲームデータ関連
#include "data/res_data/player/player.h"
#include "data/res_data/field/ground_line.h"
#include "data/res_data/enemy/enemy_manager.h"
#include "data/res_data/enemy/test_enemy.h"
#include "data/res_data/UI/hp_ui.h"
#include "data/res_data/UI/dp_ui.h"
#include "data/res_data/UI/enemy_destory_ui.h"
#include "data/res_data/UI/hp_recovery_ui.h"
#include "data/res_data/UI/cp_recovery_ui.h"


using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidEngineInput input;
	DiploidCollision collision;

	EnemyManager enemy_manager;//敵の管理
	_TestEnemy test_enemy;//敵オブジェクト
	EnemyData enemy_data;

	Player player;//プレイヤー
	GroundLine ground_line;//グラウンドライン

	HpUI hp_ui;
	DpUI dp_ui;
	EnemyDestoryUI enemy_destory_ui;
	HpRecoveryUI hp_recovery_ui;
	CpRecoveryUI cp_recovery_ui;

	DiploidImageV2 forest;


	DiploidImageV2 test[9];
	Animation anime;

public:
	void FileCreate();//ゲーム起動時に一度だけファイルを作る処理。
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。	
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理
	void Destory();//削除する処理。
	void End();//engine終了前処理。
};