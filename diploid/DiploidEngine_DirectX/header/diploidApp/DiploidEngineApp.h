//中枢です。
#pragma once
#include <vector>
#include "DxLib.h"//Dxlib本体
#include "diploidApp\DiploidEngineMain.h"//心臓部分(必ず呼ぶ)
#include "diploidObject\DiploidEngineObject.h"//円や四角や画像や音など、オブジェクト全般
#include "system\DiploidEngineMath.h"//数学式関連(DxLibもしくはC++標準もしくはその他の数学ライブラリの使用を推奨)

//スタンドアローン関連
#include "diploidStandalone\standalone.h"//未実装

//ゲームデータ関連
#include "data/number.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidObject object;

	int json_test;
	float json_pi;
	std::string json_string;

public:
	void FileCreate();//ゲーム起動時に一度だけファイルを作る処理。
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。	
	void LoadUpdata();//ループ中に一度だけデータをロードしたい処理を記述。(仮)
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理
	void End();//engine終了前処理。
};