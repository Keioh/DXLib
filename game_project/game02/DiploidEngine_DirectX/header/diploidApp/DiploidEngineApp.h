//中枢です。
#pragma once
#include <vector>
#include "DxLib.h"//Dxlib本体
#include "diploidApp\DiploidEngineMain.h"//心臓部分(必ず呼ぶ)
#include "diploidObject\DiploidEngineObject.h"//円や四角や画像や音など、オブジェクト全般
#include "system\DiploidEngineMath.h"//数学式関連(DxLibもしくはC++標準もしくはその他の数学ライブラリの使用を推奨)
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"

//スタンドアローン関連
#include "diploidStandalone\standalone.h"//未実装

//ゲームデータ関連
#include "data/number.h"


class DiploidEngineApp : public DiploidEngineMain
{
private:
	//UI
	DiploidSystem kaitaku_system;//開拓ワンショットロード
	DiploidSystem nougyou_system;//農業区ワンショットロード
	DiploidSystem syougyou_system;//商業区ワンショットロード
	DiploidSystem sangyou_system;//産業区ワンショットロード
	DiploidSystem zikkou_system;//実行ワンショットロード
	DiploidSystem sarati_system;//更地ワンショットロード
	VECTOR ku_position;//UIのポジション
	DiploidUI nougyou;//農業区ボタン
	DiploidUI sangyou;//産業区ボタン
	DiploidUI syougyou;//商業区ボタン
	DiploidUI sarati;//更地ボタン
	DiploidUI kaitaku;//開拓ボタン
	DiploidUI zikkou;//実行ボタン
	DiploidUI play;//プレイボタン
	bool nougyou_sangyou_syougou_flags;//農業区と産業区と商業区のボタンのフラグを保存。(全て0なら0を返して、どれか一つでも1があれば1を返す)
	int play_type;//ゲーム速度のフラグ

	//フィールド
	VECTOR field_position;//区域のポジション
	DiploidUI field[9];//区域
	bool field_all_flag;//区域の選択フラグを保存(全て0なら0を返して、どれか一つでも1があれば1を返す)
	int field_type[9];//区域のタイプ(商区なのか産区なのか農区なのか)

	DiploidObject mouse_point;//マウスポイント用


public:
	void FileCreate();//ゲーム起動時に一度だけファイルを作る処理。
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。	
	void LoadUpdata();//ループ中に一度だけデータをロードしたい処理を記述。(仮)
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理
	void End();//engine終了前処理。
};