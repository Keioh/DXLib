#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{
	my_castle.Load();//自拠点のロード

	command_ui.Load();
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	//マウスカーソル
	mouse_point.point.Init(VGet(0, 0, 0));
	mouse_point.point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(mouse_point.point);

	//自分の拠点
	my_castle.Inti(VGet(GetWindowSize().x / 2, GetWindowSize().y / 2, 0), 50);
	my_castle.Push(diploidEngineImpact);

	//コマンドUI
	command_ui.Init(VGet(0, 200, 0));
	command_ui.Push(diploidEngineImpact);

	//オブジェクト番号の自動振り分け
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	my_castle.Updata(diploidEngineImpact, diploidEngineInput);//自拠点アップデート

	command_ui.Updata(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	my_castle.Draw(true,true);//自拠点の描写
	command_ui.Draw();
}

void DiploidEngineApp::End()//engine終了前処理。
{

}