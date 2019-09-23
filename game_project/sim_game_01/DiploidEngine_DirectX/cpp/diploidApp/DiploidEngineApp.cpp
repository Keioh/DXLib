#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{
	command_ui.Load();//コマンドUIのロード
	season_panel.Load();//季節パネルのロード

	status_bar.image.Load("texter/game/status_bar/status_bar.png");
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{	
	//マウスカーソル(UI画面)
	mouse_point.point.Init(VGet(0, 0, 0));
	mouse_point.point.mouse_point_move_flag = true;
	mouse_point.point.layer_number = DIPLOID_LAYER_00;
	diploidEngineImpact.PushPoint(mouse_point.point);

	//コマンドUIの初期化とプッシュ
	command_ui.Init(VGet(0, 128, 0));
	command_ui.Push(diploidEngineImpact);

	//季節パネルの初期化とプッシュ
	season_panel.Init(VGet(0, 0, 0));
	//season_panel.Push(diploidEngineImpact);//今のところ中身なし


	status_bar.image.Init(VGet(0 + (640 / 2), 0 + (128 / 2), 0));


	//オブジェクト番号の自動振り分け
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//コマンドUIのアップデート
	command_ui.Updata(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput);

	//季節パネルのアップデート
	season_panel.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//現在は当たり判定は使ってないけど、アニメーションで使用

	static int count;
	count++;

	if (count > 30)
	{
		season_panel.NextDays();
		count = 0;
	}

	status_bar.image.Updata();

	//オブジェクト番号の自動振り分け
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//コマンドUIの描写
	command_ui.Draw();

	//季節パネルの描写
	season_panel.Draw();

	status_bar.image.Draw();
}

void DiploidEngineApp::End()//engine終了前処理。
{

}