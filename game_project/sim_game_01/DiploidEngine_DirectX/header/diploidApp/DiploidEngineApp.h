//中枢です。
#pragma once
#include <vector>
#include "DxLib.h"//Dxlib本体
#include "diploidApp\DiploidEngineMain.h"//心臓部分(必ず呼ぶ)
#include "diploidObject\DiploidEngineObject.h"//円や四角や画像や音など、オブジェクト全般
#include "system\DiploidEngineMath.h"//数学式関連(DxLibもしくはC++標準もしくはその他の数学ライブラリの使用を推奨。というか中身ない)

#include "diploid3D/diploidPanel.h"

//スタンドアローン関連
#include "diploidStandalone\standalone.h"//未実装

//ゲームデータ関連
#include "data/number.h"

//UI
#include "data/game_data/UI/command_ui.h"
#include "data/game_data/UI/season_panel.h"
#include "data/game_data/UI/status_bar.h"

#include "data/game_data/EXPLORE/explore_test_map.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidObject mouse_point;//マウスカーソルの判定用

	CommandUI command_ui;//コマンドUI
	SeasonPanel season_panel;//季節パネル
	StatusBar status_bar;//ステータスバー

	Explore_TestMap test_map;

	//時計
	DiploidObject test_clock_back;
	DiploidObject test_clock_hour_hand;
	DiploidObject test_clock_minute_hand;
	DiploidObject test_clock_second_hand;
	int timer = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;


public:
	void FileCreate();//ゲーム起動時に一度だけファイルを作る処理。
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。	
	void LoadUpdata();//ループ中に一度だけデータをロードしたい処理を記述。(未実装。一度だけロード等したい場合はDiploidSystemを使ってください。)
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理
	void End();//engine終了前処理。
};