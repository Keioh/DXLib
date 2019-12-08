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
	//資源
	int sakumotu = 50;//作物
	int sikinn = 1000;//資金
	int sannsyutu = 10;//産出
	int jinkou = 10;//人口

	float sakumotu_scale[9];
	float sikinn_scale[9];
	float sannsyutu_scale[9];
	float all_basic_scale = 0.025f;

	int sakumotu_syuunyuu;//作物の収入情報
	int sikin_syuunyuu;//資金の収入情報
	int sannsyutu_syuunyuu;//産出の収入情報
	int jinkou_zouka;//人口増加量の情報
	int sakumotu_syouhi;//作物の消費情報

	DiploidObject status;//ステータス画像
	DiploidObject status_down;//ステータス下部の画像

	int fps_time;//フレームレートの時間(60fps)
	int second;//秒
	int minute;//分
	int hour;//時
	int day;//日

	bool second_flag;//一秒進んだらtrueになる
	bool minute_flag;//一分進んだらtrueになる
	bool hour_flag;//一時進んだらtrueになる
	bool day_flag;//一日進んだらtrueになる

	//UI
	VECTOR ku_position;//UIのポジション
	DiploidSystem kaitaku_system;//開拓ワンショットロード
	DiploidSystem nougyou_system;//農業区ワンショットロード
	DiploidSystem syougyou_system;//商業区ワンショットロード
	DiploidSystem sangyou_system;//産業区ワンショットロード
	DiploidSystem zikkou_system;//実行ワンショットロード
	DiploidSystem sarati_system;//更地ワンショットロード
	DiploidUI nougyou;//農業区ボタン
	DiploidUI sangyou;//産業区ボタン
	DiploidUI syougyou;//商業区ボタン
	DiploidUI sarati;//更地ボタン
	DiploidUI kaitaku;//開拓ボタン
	DiploidUI zikkou;//実行ボタン
	DiploidUI play;//プレイボタン
	bool nougyou_sangyou_syougou_flags;//農業区と産業区と商業区のボタンのフラグを保存。(全て0なら0を返して、どれか一つでも1があれば1を返す)
	int play_type;//ゲーム速度のフラグ

	DiploidObject kaitaku_nouku[9];//農区を開拓中の画像
	DiploidObject kaitaku_syouku[9];//商区を開拓中の画像
	DiploidObject kaitaku_sanku[9];//産区を開拓中の画像
	DiploidObject kaitaku_sarati[9];//更地を開拓中の画像
	DiploidObject double_1_025[9];//1.05倍の画像
	DiploidObject double_1_05[9];//1.05倍の画像
	DiploidObject nouku_setumei;//農区の説明画像
	DiploidObject syouku_setumei;//商区の説明画像
	DiploidObject sanku_setumei;//産区の説明画像
	DiploidObject kaitaku_setumei;//開拓の説明画像
	DiploidObject sarati_setumei;//更地の説明画像
	DiploidObject play_setumei;//プレイボタンの説明画像

	//フィールド
	VECTOR field_position;//区域のポジション
	DiploidUI field[9];//区域
	bool field_all_flag;//区域の選択フラグを保存(全て0なら0を返して、どれか一つでも1があれば1を返す)
	int field_type[9];//区域のタイプ(商区なのか産区なのか農区なのか)
	int kaitaku_time[9];//開拓時間
	int kaitaku_type[9];//開拓のタイプ（商区なのか産区なのか農区なのか）

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