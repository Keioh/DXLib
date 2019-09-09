#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{
	object.file.LoadJSON("json/test.json");	//jsonファイル読み込み
	json_test = object.file.GetJSON()["test"];//"test"のデータを読み取る。
	json_pi = object.file.GetJSON()["pi"];//"pi"のデータを読み取る。
	json_string = object.file.GetJSON()["world"].dump();//文字列は文字化け。これは英字でも同じ。

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{

}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{

}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", json_test);//"test"の中身を出力
	DrawFormatString(0, 20, GetColor(0, 0, 0), "%f", json_pi);//"pi"の中身を出力
	DrawFormatString(0, 40, GetColor(0, 0, 0), "%s", json_string);//文字化け

}

void DiploidEngineApp::End()//engine終了前処理。
{

}