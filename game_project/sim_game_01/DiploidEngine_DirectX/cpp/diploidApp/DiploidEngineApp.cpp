#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{
	command_ui.Load();//コマンドUIのロード
	season_panel.Load();//季節パネルのロード
	status_bar.Load();//ステータスバーのロード
	clock.Load();//時計のロード

	test_map.Load();
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


	//時計の初期化
	clock.Init();


	//ステータスバーの初期化とプッシュ
	status_bar.Init(VGet(0, 0, 0));
	//status_bar.Push(diploidEngineImpact);//今のところ中身なし


	test_map.Init(VGet(1280/2, 720/2, 0));
	test_map.Push(diploidEngineImpact);

	//オブジェクト番号の自動振り分け
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//日を進める
	if (clock.isDayFlag() == true)
	{	
		//次の日へ
		season_panel.NextDays();
	}

	//敵に当たっていなければ
	if (test_map.GetEnemyHitFlag() == false)
	{
		//コマンドUIのアップデート
		command_ui.Updata(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput);
	}

	//コマンドUIがオフなら
	if (command_ui.GetUIFlag() == false)
	{	
		//マップのアップデート(移動など)
		test_map.Updata(diploidEngineImpact, diploidEngineInput, command_ui, status_bar, clock);

		//敵に当たっていなければ
		if (test_map.GetEnemyHitFlag() == false)
		{
			//時計のアップデート
			clock.Update();

			//ステータスバーのアップデート
			status_bar.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//現在は当たり判定は使ってないけど、アニメーションで使用
			status_bar.StatusUpdate(command_ui.information_command);//ステータスバーの数値をコマンドUIからの情報を用いて更新

			//季節パネルのアップデート
			season_panel.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//現在は当たり判定は使ってないけど、アニメーションで使用
		}
	}

	//オブジェクト番号の自動振り分け
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{	
	//テストマップの描写(プレイヤーもここに含まれる)
	test_map.Draw();

	//敵に当たっていなければ
	if (test_map.GetEnemyHitFlag() == false)
	{
		//コマンドUIの描写
		command_ui.Draw();

		//ステータスバーの描写
		status_bar.Draw();
		status_bar.StatusDraw(command_ui.information_command);//ステータスバーにコマンドUIからの数値を出力

		//季節パネルの描写
		season_panel.Draw();

		//時計
		clock.Draw();
	}
}

void DiploidEngineApp::End()//engine終了前処理。
{

}