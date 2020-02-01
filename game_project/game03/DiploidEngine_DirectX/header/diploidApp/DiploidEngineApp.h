//中枢です。
#pragma once
#include <list>
#include <memory>
#include "DxLib.h"//Dxlib本体
#include "diploidApp\DiploidEngineMain.h"//心臓部分(必ず呼ぶ)
#include "diploidObject\DiploidEngineObject.h"//円や四角や画像や音など、オブジェクト全般
#include "system\DiploidEngineMath.h"//数学式関連(DxLibもしくはC++標準もしくはその他の数学ライブラリの使用を推奨)
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"//一回だけデータを読み込むための処理群

#include "ver2.0/Graphics/DiploidCircleV2.h"//Ver2.0の円クラス
#include "ver2.0/Main/Collision.h"//Ver2.0の当たり判定処理

//スタンドアローン関連
#include "diploidStandalone\standalone.h"//未実装

//ゲームデータ関連
#include "data/number.h"

using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidCollision collision;//当たり判定の処理クラス

	DiploidCircleV2 player_main;//プレイヤー本体
	DiploidCircleV2 player_grays;//プレイヤーのグレイズ域
	DiploidCircleV2 player_bullet;//プレイヤーの弾丸
	list<DiploidCircleV2> player_bullet_list;//プレイヤーの弾丸のリスト

	DiploidCircleV2 grays_bullet;//グレイズ用の弾丸
	list<DiploidCircleV2> grays_bullet_list;//敵に当たらないグレイズ用の弾丸のリスト

	DiploidEngineInput input;

	float slow = 1.0f;//プレイヤーの移動速度の倍率

	int is_count = 20;//プレイヤー弾の発射頻度調整用
	int grays_count = 0, grays_is_count = 10;//グレイズのカウント数。

public:
	void FileCreate();//ゲーム起動時に一度だけファイルを作る処理。
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。	
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理
	void Destory();//削除する処理。
	void End();//engine終了前処理。
};

//目標：グレイズで弾いて攻撃する、縦か横のシューティングゲーム